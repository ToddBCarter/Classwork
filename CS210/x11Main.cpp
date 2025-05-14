#include "w11.cpp"
using namespace std;

int main()
{
   cout << "A static type Animal can be Animal, Dog, PetDog or PetCat" << endl;
   cout << endl << "   As static Animal dynamic Animal" << endl;
   Animal * pAnimal1 = new Animal();
   pAnimal1->Speak1();
   pAnimal1->Speak2();
   pAnimal1->Speak3();

   cout << endl << "   As static Animal dynamic Dog" << endl;
   Animal * pAnimal2 = new Dog();
   pAnimal2->Speak1();
   pAnimal2->Speak2();
   pAnimal2->Speak3();

   cout << endl<< "   As static Animal dynamic PetDog" << endl;
   Animal * pAnimal3 = new PetDog();
   pAnimal3->Speak1();
   pAnimal3->Speak2();
   pAnimal3->Speak3();

   cout << endl << endl << "A static type Dog can be Dog or PetDog" << endl;
   cout << endl << "   As static Dog dynamic Dog" << endl;
   Dog * pDog1 = new Dog();
   pDog1->Speak1();
   pDog1->Speak2();
   pDog1->Speak3();

   cout << endl<< "   As static Dog dynamic PetDog" << endl;
   Dog * pDog2 = new PetDog();
   pDog2->Speak1();
   pDog2->Speak2();
   pDog2->Speak3();
}


