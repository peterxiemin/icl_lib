icl_lib
=======

一个C/C++开发库：方便我们在开发项目的时候，可以将时间和精力投入到业务逻辑上，而不是基础的底层代码上，从而大大提高开发效率和项目的鲁棒性。

###一、网络模型

三种常用模型支持http协议解析（引入第三方http_parse)，可以使用`webbench -cxx -txx http://xxx.xxx.xxx.xxx`进行性能测试

>1、icl_lib/samples/net/serv_single_process 单进程单线程模型

>2、icl_lib/samples/net/serv_mutiple_process 多进程单线程模型

>3、icl_lib/samples/net/serv_mutiple_thread 单进程多线程模型

>4、 对select和epoll进行了封装

>5、 实现了简单的tcp客户端程序

>6、 对常用的网络API，如fcntl，set/getsockopt等函数进行了封装

>7、 重点对socket的read和write进行了不用类型的封装

>8、 添加基于epoll的多进程模型, 并对是否共享epoll_create返回的描述符问题上，做了详细的测试请参考./sample/net/serv_mutipole_process_with_epoll，代码中有详细注释

>9、 添加基于libevent的单进程单线程模型

###二、高级数据结构

参考stl库，实现了以上三种常用的数据结构

>1、icl_lib/samples/array

>2、icl_lib/samples/queue(list)

>3、icl_lib/samples/htable

###三、系统相关

>1、对多进程编程的相关函数进行了封装

>2、对多线程编程的相关函数进行了封装

>3、对在linux常用的如pipe，dup、execve等函数进行了封装

>4、对时间函数进行了封装

>5、对字符串处理函数进行了部分实现

>6、实现了日志处理模块，可以定日志级别和选择输入目标

>7、对unix下的标准io和文件io进行了封装

###四、业务相关

引入常用的第三方库并在samples实现了常用的增删查改等操作

>1、引入libmysqlclient_r 详见icl_lib/samples/mysql

>2、添加mysqlapi，加入非查询操作的缓冲机制，重连机制和详细的mysql的error信息打印

>3、引入libmemcached 详见icl_lib/samples/memcached

>4、引入libhiredis 详见icl_lib/samples/redis-cli

>5、引入libcurl 详见icl_lib/samples/curl

>6、引入libevent， 详见icl_lib/samples/serv_libevent

