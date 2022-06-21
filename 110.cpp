 #include <bits/stdc++.h>
using namespace std;
 
 //map 映射的使用
int  main ()
{

 map<int, string> m;  
   m[1] = "student_one";  
    m[2] = "student_two";  
   m[3] = "student_three";  
    map<int, string>::iterator iter;  
    for(iter = m.begin(); iter != m.end(); iter++)  
        cout<<iter->first<<' '<<iter->second<<endl;  

return 0;
}
