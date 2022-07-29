 

# 简介 Abstract

pktorrent is a open source, one file, small p2p torrent sdk  base on libtorrent.

By using C++ interface, you can create a p2p client just just some line code.

----

pktorrent是一个开源的、单文件、基于libtorrent的，p2p torrent 开发库。

通过其导出的C++接口，几行代码即可创建一个p2p客户端。


----

# 特性 Features

- 支持磁力magnet连接，torrent文件下载
- 支持Windows 、linux、android、IOS平台
- 完善的接口，支持生成torrent文件，支持磁力连接下载等

----

# 使用 Usage

打开一个文件并做种：

TORRENT_FILE file;

Pktorrent::add_torrent(-1, file, "c:\\test.mp4",0); 

获取文件的磁力链接地址:

char magneturl[1024];

Pktorrent::get_file_magneturl(purl, magneturl, sizeof(magneturl));

生成torrent文件

generate_file_torrent("c:\\test.mp4", "c:\\test.mp4.torrent");


下载磁力链接

TORRENT_FILE file;

Pktorrent::add_torrent(-1, file, "magnet:?xt=urn:btih:14d8f4cb4def87f954a04a41d3fb1e572ecc7ada","d:\\"); 

**Usage**


# 编译 Build

不推荐自己编译。请下载编译好的库文件使用。

----

# 联系方式

大家有问题可以选择：

- 加Q群466907566


- github里留言issue讨论
 

----
