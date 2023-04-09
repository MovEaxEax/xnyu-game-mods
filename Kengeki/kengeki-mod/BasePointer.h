#pragma once

struct BasePointer
{
	void* baseAddress;
	std::vector<void*> offsets;
};

struct ReturnValue
{
	void* _void_ptr;
	bool _success;
	float _float_value;
	double _double_value;
	int _int32_value;
	long long _int64_value;
	std::string _string_value;
	BYTE _byte_value;
	bool _bool_value;
	BYTE* _byte_ptr;
};

struct ParameterValue
{
	BasePointer _basepointer;
	void* _address;
	void* _dst;
	void* _src;
	int _amount;
	int _size;
	float _float_value;
	double _double_value;
	int _int32_value;
	long long _int64_value;
	std::string _string_value;
	BYTE _byte_value;
	bool _bool_value;
	BYTE* _byte_ptr;
};

// Struct to handle the return values
ReturnValue ret;
ParameterValue par;

void DbgResolveBasePointer()
{
	__try
	{
		void* finalAddress = par._basepointer.baseAddress;
		for (int i = 0; i < par._basepointer.offsets.size(); i++)
		{
			std::memcpy(finalAddress, finalAddress, sizeof(void*));
			finalAddress = (void*)((long long)finalAddress + (long long)par._basepointer.offsets[i]);
		}
		ret._void_ptr = finalAddress;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		ret._void_ptr = nullptr;
	}
}




