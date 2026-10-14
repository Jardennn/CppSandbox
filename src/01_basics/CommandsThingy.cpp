#include <iostream>;

// This is some code I copied from a video I saw online for learning from it and understanding a bit more how input works.
// I'm pretty familiar with the if statement and the loops settings ups.
int main()
{
  std::string input;
  while (true)
  {
    std::cout << "> ";
   /* if (!(std::cin >> input))
    {
      break;
    }*/
    std::cin >> input;

    if (input == "horse")
    {
      std::cout << "meow\n";
    }
    
    else
    {
      std::cout << "Cat\n";  
    }
  }
}
