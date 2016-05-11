// task01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "HttpUrl.h"
#include <iostream>

int main()
{
	CHttpUrl hi("https://habrahabr.ru/post/64226/");
	std::cout << hi.GetURL() << std::endl;
	CHttpUrl hasi("http://s:20/asdas.hrw");
	std::cout << hasi.GetURL() << std::endl;
	CHttpUrl hassi("http://yandex.com");
	std::cout << hassi.GetURL() << std::endl;
	CHttpUrl dssd("http://javascript.ru/forum/events/5715-regulyarnoe-vyrazhenie-dlya-proverki-url.html");
	std::cout << dssd.GetURL() << std::endl;
    return 0;
}

