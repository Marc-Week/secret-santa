#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sys/time.h>

using namespace std;


//this program makes a secret santa file for a family so that spouces arnt eachother santa.

struct giver//Person who is being emailed
{
  char * name;//giver
  giver * spouse;//spouce
  giver * recp;//recipient
};

int main(void)
{
  bool used[6];//has it been used
  for (int i = 0; i < 6; ++i) used[i] = 1;
  

  giver family[6];
  family[0].name = "Marc";
  family[0].spouse = &family[3];

  family[1].name = "Matt";
  family[1].spouse = &family[2];
 
  family[2].name = "Taylor";
  family[2].spouse = &family[1];

  family[3].name = "Stef";
  family[3].spouse = &family[0];

  family[4].name = "Roxann";
  family[4].spouse = &family[5];

  family[5].name = "Tim";
  family[5].spouse = &family[4];

  struct timeval  tv1, tv2, tvdiff;//random seeder
  gettimeofday(&tv1, NULL);
  int time = tv1.tv_sec;
  srand(time);//seeds the randomizer;

 
  for (int i = 0; i < 6; i++)
  {
   int gift;
    if (i == 4 && used[5]){// if the last two are their own spouse restart // might look to more effciant way to prevent this
      i = 0;
      used[0] = used[1] = used[2] = used[3] = used[4] = used[5] = 1;
    }
   do
   {
      gift = rand() % 6;
    
        
   }while( !used[gift] || i == gift || family[i].spouse == &family[gift]); 
   family[i].recp = &family[gift];
   used[gift] = 0;

  }
  
  //create text for each member
  for (int i = 0; i < 6; ++i){
   ofstream fout;
   fout.open(family[i].name);
   fout << "Your Secret santa is " << family[i].recp->name;
   fout.close();
  }

    return 0;
}

