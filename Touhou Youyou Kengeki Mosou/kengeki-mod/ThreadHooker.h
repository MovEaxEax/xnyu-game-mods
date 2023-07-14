#pragma once

// Thread hooker reference struct
struct ThreadReferences
{
    void* ThreadHookerGetThreadCount;
    void* ThreadHookerGetThreads;
    void* ThreadHookerGetSafeThreadCount;
    void* ThreadHookerGetSafeThreads;
    void* ThreadHookerSuspendThreads;
    void* ThreadHookerResumeThreads;
    void* ThreadHookerCreateThread;
    void* ThreadHookerCreateRemoteThread;
    void* ThreadHookerCreateRemoteThreadEx;
};
ThreadReferences ThreadHookerReferences;

// Thread hooker typedefs
typedef HANDLE(WINAPI* ThreadHookerCreateThreadT)(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
ThreadHookerCreateThreadT pThreadHookerCreateThread = nullptr;
typedef HANDLE(WINAPI* ThreadHookerCreateRemoteThreadT)(HANDLE hProcess, LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
ThreadHookerCreateRemoteThreadT pThreadHookerCreateRemoteThread = nullptr;
typedef HANDLE(WINAPI* ThreadHookerCreateRemoteThreadExT)(HANDLE hProcess, LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList, LPDWORD lpThreadId);
ThreadHookerCreateRemoteThreadExT pThreadHookerCreateRemoteThreadEx = nullptr;
typedef int(__stdcall* ThreadHookerGetThreadCountT)();
ThreadHookerGetThreadCountT pThreadHookerGetThreadCount = nullptr;
typedef int(__stdcall* ThreadHookerGetSafeThreadCountT)();
ThreadHookerGetSafeThreadCountT pThreadHookerGetSafeThreadCount = nullptr;
typedef std::unordered_set<DWORD>(__stdcall* ThreadHookerGetThreadsT)();
ThreadHookerGetThreadsT pThreadHookerGetThreads = nullptr;
typedef std::unordered_set<DWORD>(__stdcall* ThreadHookerGetSafeThreadsT)();
ThreadHookerGetSafeThreadsT pThreadHookerGetSafeThreads = nullptr;
typedef bool(__stdcall* ThreadHookerSuspendThreadsT)(int sleep); // Sleep is optional, set it to 0 if not needed
ThreadHookerSuspendThreadsT pThreadHookerSuspendThreads = nullptr;
typedef bool(__stdcall* ThreadHookerResumeThreadsT)(int sleep); // Sleep is optional, set it to 0 if not needed
ThreadHookerResumeThreadsT pThreadHookerResumeThreads = nullptr;


