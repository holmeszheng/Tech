#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <tuple>
using namespace std;
int main()
{
//tuple
    tuple<int, string, double> myTuple(1,"string",5.2);
    //cout<<get<0>(myTuple)<<"   "<<get<1>(myTuple)<<"   "<<get<2>(myTuple)<<endl;
//bitset
    bitset<8> myBits(1L);
    //cout<<myBits.to_ulong()<<endl;
//enumeration
    enum days {MONDAY=2, TUESDAY=1,WEDNESDAY};
    days today = MONDAY;
    //cout<<(MONDAY==WEDNESDAY)<<endl;
//Sequential Containers
    vector<int> vecInt = {1,2,3,4,5,6,7};
    string str = "1992.1020";
    array<int, 5> arrayInt();
//    sort(vecInt.begin(),vecInt.end(),greater<int>());
//    for_each(vecInt.begin(),vecInt.end(),[](int a){cout<<a<<endl;});

    list<int> listInt(vecInt.begin(),vecInt.end());
    forward_list<int> flistInt(vecInt.begin(),vecInt.end());
    deque<int> dInt(vecInt.begin(),vecInt.end());

//Adaptors
    priority_queue<int,vector<int>,greater<int>> pqInt(vecInt.begin(),vecInt.end(),greater<int>());
//    while(!pqInt.empty())
//    {
//        cout<<pqInt.top()<<endl;
//        pqInt.pop();
//    }
    stack<int> sInt;
    queue<int> qInt;

//Associatvie Containers
//pair
    pair<int, string> a = {1,"hello"};
    pair<int, string> b = {2,"world"};
//set
    set<int>  setInt({1,2,3,4,5});
    setInt.insert(6);
    setInt.insert(vecInt.begin(),vecInt.end());
   //for_each(setInt.begin(),setInt.end(),[](int a){cout<<a<<endl;});
    set<int,greater<int>> setInt2(setInt.begin(),setInt.end(),greater<int>());
// If callable used in set
//    for(set<int,greater<int>>::iterator it = setInt2.begin(); it!= setInt2.end(); it++)
//        cout<<*it<<endl;
    unordered_set<int> unSetInt(vecInt.begin(),vecInt.end());

//map
    map<int, string> myMap({{1,"a"},{2,"b"},{3,"c"}});
    myMap.insert({{4,"d"},{5,"e"}});
// If callable used in map
    map<int, string,greater<int>> myMap2(myMap.begin(),myMap.end(),greater<int>());
    unordered_map<int,string> unMapInt(myMap.begin(),myMap.end());

//    for(map<int,string,greater<int>>::iterator it = myMap2.begin(); it!= myMap2.end(); it++)
//    {
//        cout<<it->first<<"      :"<<it->second<<endl;
//    }
//    myMap2[1] = "w";
//    for(map<int,string,greater<int>>::iterator it = myMap2.begin(); it!= myMap2.end(); it++)
//    {
//        cout<<it->first<<"      :"<<it->second<<endl;
//    }
    //equal range得到 [b, e)
//    pair<map<int,string,greater<int>>::iterator, map<int,string,greater<int>>::iterator> p =
//        myMap2.equal_range(2);
    //equal to [lowe_bound(2), upper_bound(2))
//    map<int,string,greater<int>>::iterator p11 = myMap2.lower_bound(2);
//    auto p22 = myMap2.upper_bound(2);



//Occasions when iterators become invalid

    /*数组结构的insert导致iterator全部失效.
    erase导致当前iterator失效*/
//    for(vector<int>::iterator it = vecInt.begin(); it!=vecInt.end();)
//    {
//
//        if(*it == 3)
//        {
//            it=vecInt.erase(it); //returned iterator points to next element
//        }
//        else
//        {
//            cout<<*it<<endl;
//            it++;
//        }
//    }
//    for(deque<int>::iterator it =dInt.begin(); it!=dInt.end();)
//    {
//        if(*it==3)
//        {
//            it=dInt.insert(it,100); //returned iterator points to the element inserted
//            it+=2;
//        }
//        else
//        {
//            cout<<*it<<endl;
//            it++;
//        }
//    }
//    for_each(dInt.begin(),dInt.end(),[](int arg0){cout<<arg0<<endl;});

/*对于List,insert不会使iterator失效, erase会使当前iterator失效*/
//for(list<int>::iterator it = listInt.begin(); it !=listInt.end();)
//{
//    if(*it ==3)
//    {
//        it=listInt.erase(it);
//    }
//    else
//    {
//        cout<<*it<<endl;
//        it++;
//    }
//}

//对于set, map. insert不会使迭代器失效，erase会使当前迭代器失效。
    //set
//   for(set<int>::iterator it = setInt.begin(); it!=setInt.end();)
//    {
//        if(*it == 3)
//        {
//            it=setInt.erase(it);
////            it++;
//
//        }
//        else
//        {
//            cout<<*it<<endl;
//            it++;
//        }
//    }
//    for_each(setInt.begin(),setInt.end(),[](int arg0){cout<<arg0<<endl;});

    //unordered_set
//   for(unordered_set<int>::iterator it = unSetInt.begin(); it!=unSetInt.end();)
//    {
//        if(*it == 3)
//        {
//            it=unSetInt.erase(it);
////            it++;
//
//        }
//        else
//        {
//            cout<<*it<<endl;
//            it++;
//        }
//    }
//    cout<<" \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<<endl;
//    for_each(unSetInt.begin(),unSetInt.end(),[](int arg0){cout<<arg0<<endl;});

    //map
    for(map<int,string>::iterator it = myMap.begin(); it!=myMap.end();)
    {
        if(it->first == 3)
        {
            it = myMap.erase(it);
            //it++;
        }
        else
        {
            cout<<it->first<<":         "<<it->second<<endl;
            it++;
        }
    }
        for_each(myMap.begin(),myMap.end(),[](pair<int,string> arg0){cout<<arg0.first<<"          "<<arg0.second<<endl;});


        /*Conclusion: 只有顺序容器（array based）的insert会使iterator失效， 所有的erase都会使当前迭代器失效*/
}
