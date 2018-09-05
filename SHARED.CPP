#include <iostream>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main(){


int segmentid ,pid;
char *memory ;
const int size=2048;
segmentid=shmget(IPC_PRIVATE,size,S_IRUSR|S_IWUSR);
if(segmentid==-1)
cout<<"Shared Memory Allocation Failed ....\n";
else{
memory=(char*)shmat(segmentid,NULL,0);
pid=fork();
if(pid==-1)
cout<<"fork creation failed ...\n";
else if(pid==0)
{
cout<<"Child Writing to shared memory ..../n";
sprintf(memory,"hello world !!!");


}
else if(pid>0)
{
  wait(NULL);
  cout<<"Parent Reading from Shared Memory...\n";
  cout<<"\n Message:"<<memory<<"\n";

}
shmdt(memory);
shmctl(segmentid,IPC_RMID,NULL);
}
return 0;












}
