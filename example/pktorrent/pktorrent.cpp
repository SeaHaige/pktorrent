/**
Copyright (c) 2018 SeaHaige

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software. If you use this software
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.

3. This notice may not be removed or altered from any source
distribution.

*/

#include <iostream>
#include <thread>
#include <chrono>

#include "pktorrent.h"

#pragma comment(lib,"..\\..\\lib\\windows\\pktorrent.lib")
using namespace Pktorrent;
 
int main(int argc,char*argv[])
{
    char* p1 = Pktorrent::get_version();

    printf("\r\n>>%s\r\n\r\n", p1);
    if (argc == 1) {
        printf("software usage :\r\n"
"       pktorrent.exe c:\test.mp4\r\n"
"       pktorrent.exe magnet:?xt=urn:btih:14d8f4cb4def87f954a04a41d3fb1e572ecc7ada a.mp4\r\n"
            );
        return 0;
    }
    TORRENT_FILE  file;
    char* purl = argv[1]; 
    set_listen_port(6881, 0);

    if (strncmp(purl, "magnet:", 7) == 0) {
        char* path =(char*) ((argc > 2) ? argv[2] : "./");
        printf("  downloading: %s -> %s ...\n", purl, path);

        int hd=add_torrent(-1, file, purl,(char*)path); 

        while (1) {
            int f=check_torrent_finish(file);
            if (f == 1) {
                printf("  downloaded.                              \n");
                break;
            }
            printf("  %I64d/%I64d\r", get_downloaded_size(file), get_file_size(file));
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        printf("  seeding...                            \n");
    }
    else {
        char magneturl[1024];
        get_file_magneturl(purl, magneturl, sizeof(magneturl));
        add_torrent(-1, file, purl, 0);
        
        printf("  seeding file:%s -> %s\n",purl, magneturl);
    }
    char c;
    std::cin >> c;
    return 0;
} 

