#pragma once

struct SigScanParameter
{
	int _pattern_size;
	int* _pattern_mask;
	BYTE* _bytes_scan;
	BYTE* _bytes_check;
	long long _dst_offset;
	void* _start;
	void* _end;
	long long _amount;
	void* _finding;
	bool _success;
};

SigScanParameter ssp;

void _DbgSigScanAll()
{
	__try
	{
		ssp._finding = nullptr;
		ssp._success = false;
		long long offset = 0;
		while (true)
		{
			bool found = true;
			int check_index = 0;
			std::memcpy(ssp._bytes_scan, (void*)((long long)ssp._start + offset), ssp._pattern_size);
			for (int i = 0; i < ssp._pattern_size; i++)
			{
				if (ssp._pattern_mask[i] != 1) continue;
				if (ssp._bytes_scan[i] != ssp._bytes_check[check_index])
				{
					found = false;
					break;
				}
				check_index++;
			}

			if (found)
			{
				ssp._finding = (void*)((long long)ssp._start + offset + ssp._dst_offset);
				ssp._success = true;
				break;
			}
			else
			{
				offset++;
			}
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
	}
}

void _DbgSigScanFromTo()
{
	__try
	{
		ssp._finding = nullptr;
		ssp._success = false;
		long long offset = 0;
		void* dstAddress = ssp._start;
		while (dstAddress != ssp._end)
		{
			bool found = true;
			int check_index = 0;
			dstAddress = (void*)((long long)ssp._start + offset);
			std::memcpy(ssp._bytes_scan, dstAddress, ssp._pattern_size);
			for (int i = 0; i < ssp._pattern_size; i++)
			{
				if (ssp._pattern_mask[i] != 1) continue;
				if (ssp._bytes_scan[i] != ssp._bytes_check[check_index])
				{
					found = false;
					break;
				}
				check_index++;
			}

			if (found)
			{
				ssp._finding = (void*)((long long)dstAddress + ssp._dst_offset);
				ssp._success = true;
				break;
			}
			else
			{
				offset++;
			}
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
	}
}

void _DbgSigScanFromSize()
{
	__try
	{
		ssp._finding = nullptr;
		ssp._success = false;
		long long offset = 0;
		while (offset < ssp._amount)
		{
			bool found = true;
			int check_index = 0;
			std::memcpy(ssp._bytes_scan, (void*)((long long)ssp._start + offset), ssp._pattern_size);
			for (int i = 0; i < ssp._pattern_size; i++)
			{
				if (ssp._pattern_mask[i] != 1) continue;
				if (ssp._bytes_scan[i] != ssp._bytes_check[check_index])
				{
					found = false;
					break;
				}
				check_index++;
			}

			if (found)
			{
				ssp._finding = (void*)((long long)ssp._start + offset + ssp._dst_offset);
				ssp._success = true;
				break;
			}
			else
			{
				offset++;
			}
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
	}
}

bool SigScanPatternConversion(std::string pattern, long long* dst_offset, int* pattern_size, int* pattern_mask, BYTE* bytes_scan, BYTE* bytes_check)
{
	try
	{
		int index = 0;
		std::vector<int> patternMask;
		std::vector<BYTE> bytesToCheck;
		int findingOffset = 0;
		std::transform(pattern.begin(), pattern.end(), pattern.begin(), [](unsigned char c) { return std::tolower(c); });
		while (index < pattern.length())
		{
			if (pattern[index] == 'x')
			{
				patternMask.push_back(0);
				long long dstOff = (long long)index;
				std::memcpy(dst_offset, &dstOff, sizeof(long long));
				index++;
			}
			else if (pattern[index] == '?')
			{
				patternMask.push_back(0);
				index++;
			}
			else if (index + 1 < pattern.length())
			{
				std::string hexPair = pattern.substr(index, 2);
				if (hexPair.find_first_not_of("0123456789abcdefABCDEF", 2) == std::string::npos)
				{
					bytesToCheck.push_back((BYTE)std::stoi(hexPair, nullptr, 16));
					patternMask.push_back(1);
					index += 2;
				}
			}
			else
			{
				index++;
			}
		}

		int _pattern_size = patternMask.size();
		std::memcpy(pattern_size, &_pattern_size, sizeof(int));

		pattern_mask = new int[_pattern_size];
		for (int i = 0; i < _pattern_size; i++) pattern_mask[i] = patternMask[i];

		bytes_scan = new BYTE[_pattern_size];

		bytes_check = new BYTE[bytesToCheck.size()];
		for (int i = 0; i < bytesToCheck.size(); i++) bytes_check[i] = bytesToCheck[i];

		patternMask.clear();
		bytesToCheck.clear();

		return true;
	}
	catch (std::exception e)
	{
		return false;
	}
}

void* DbgSigScan(void* src, std::string pattern)
{
	if (!SigScanPatternConversion(pattern, &ssp._dst_offset, &ssp._pattern_size, ssp._pattern_mask, ssp._bytes_scan, ssp._bytes_check)) return nullptr;
	ssp._start = src;
	_DbgSigScanAll();
	delete[] ssp._pattern_mask;
	delete[] ssp._bytes_scan;
	return ssp._finding;
}

void* DbgSigScan(void* src, void* dst, std::string pattern)
{
	if (!SigScanPatternConversion(pattern, &ssp._dst_offset, &ssp._pattern_size, ssp._pattern_mask, ssp._bytes_scan, ssp._bytes_check)) return nullptr;
	ssp._start = src;
	ssp._end = dst;
	_DbgSigScanFromTo();
	delete[] ssp._pattern_mask;
	delete[] ssp._bytes_scan;
	return ssp._finding;
}

void* DbgSigScan(void* src, int amount, std::string pattern)
{
	if (!SigScanPatternConversion(pattern, &ssp._dst_offset, &ssp._pattern_size, ssp._pattern_mask, ssp._bytes_scan, ssp._bytes_check)) return nullptr;
	ssp._start = src;
	ssp._amount = (long long)amount;
	_DbgSigScanFromSize();
	delete[] ssp._pattern_mask;
	delete[] ssp._bytes_scan;
	return ssp._finding;
}

void* DbgSigScan(void* src, long long amount, std::string pattern)
{
	if (!SigScanPatternConversion(pattern, &ssp._dst_offset, &ssp._pattern_size, ssp._pattern_mask, ssp._bytes_scan, ssp._bytes_check)) return nullptr;
	ssp._start = src;
	ssp._amount = amount;
	_DbgSigScanFromSize();
	delete[] ssp._pattern_mask;
	delete[] ssp._bytes_scan;
	return ssp._finding;
}
