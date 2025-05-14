/*********************************************
 * Id: cart7982
 *
 * 
 *
 *********************************************/

#include<iostream>
using namespace std;


class Animal
{
   public:
      virtual void Speak1(){ cout << "Speak1 Animal" << endl; }
      void Speak2(){ cout << "Speak2 Animal" << endl; }
      void Speak3(){ cout << "Speak3 Animal" << endl; }
};

class Dog: public Animal
{
   public:
      void Speak1(){ cout << "Speak1 Dog" << endl; }
      void Speak2(){ cout << "Speak2 Dog" << endl; }
      virtual void Speak3(){ cout << "Speak3 Dog" << endl; }
};

class PetDog: public Dog
{
   public:
      void Speak1(){ cout << "Speak1 PetDog" << endl; }
      void Speak2(){ cout << "Speak2 PetDog" << endl; }
      void Speak3(){ cout << "Speak3 PetDog" << endl; }
};