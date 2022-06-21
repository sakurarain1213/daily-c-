/* E5
Error_code median_list(List_entry&x,List&a_list)
{ return a_list.retrieve((a_list.size()-1)/2,x);}
E8
Error_code copy(List &dest,List&source){
List_entry item;
Error_code flag=success;
while(!dest.empty()) dest.remove(0.item);
for(int i=0;i<source.size();i++)
{
 if(source.retrieve(i,item)!=success   ||   dest.insert(i,item)!=success)
 {flag=fail;}
}
 return flag;}
E11
Error_code split(List&source,List&oddlist,List&evenlist){
List_entry item;
Error_code flag=success;
for(int i=0;i<source.size();i++)
{
source.retrieve(i,item)
if(i%2==1)
{ if(venlist.insert(evenlist.size(),item)==overflow) flag=overflow;}
else
{ if(oddlist.insert(oddlist.size(),item)==overflow) flag=overflow;}
}
return flag;
}



void strcpy(String &copy,const String &original)
{
    copy=original;//等号已经重载
}
void strncpy(String &copy,const String &original,int n)
{
    const char *t=original.c_str();
    char *c=new char[n+1];
    strncpy(c,t,n);
    c[n]=0;
    copy=c;
    delete []c;
}
int strstr(String &text,const String &target)
{
int t;//找索引位置
const char *content_text=text.c_str();
char *p=strstr((char*)content_text,target.c_str());
if(p=NULL) t=-1;
else t=p-content_text;
return t;
} */