
gcc能够检测出栈上的overflow， 但是对堆中的overflow不能检测出，因此需要使用内存检测
工具asan。开启方法如下

    g++ -fsanitize=address：开启内存越界检测

[AddressSanitizer](https://www.wolfcstech.com/2019/05/19/AddressSanitizer_on_linux/)

[Clion设置](https://www.jetbrains.com/help/clion/google-sanitizers.html)