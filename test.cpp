#include <iostream>
#include <vector>
#include <fstream>
#include "Persion.pb.h"
#include "Info.pb.h"

using namespace std;

#define OUT_PUT

int main()
{

    Persion p;
#ifdef OUT_PUT

    p.add_name();
    p.set_name(0,"李华");
    p.add_name();
    p.set_name(1,"李明");
    p.add_name();
    p.set_name(2,"李强");

    p.set_age(12);
    p.set_id(3001);
    p.set_sex("男");

    p.set_color(Blue);

    Info* pinfo =  p.mutable_info();
    pinfo->set_address("上海");
    pinfo->set_number(1234);

    fstream output("myfile", ios::out | ios::binary); 
    p.SerializeToOstream(&output);
#else   
    fstream output("myfile", ios::in | ios::binary); 
    p.ParseFromIstream(&output);
    Info pinfo = p.info();
#endif
    std::cout << p.name(0) << std::endl;
    std::cout << p.name(1) << std::endl;
    std::cout << p.name(2) << std::endl;
    std::cout << p.color() << std::endl;
    std::cout << pinfo->address() << std::endl;
    return 0;
}