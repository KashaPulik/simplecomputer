#include <fstream>
#include <iostream>
#include <string>

int
write_memory_to_file (int *memory, int size, std::string filename)
{
  std::ofstream outputFile (filename, std::ios::binary);

  if (outputFile.is_open ())
    {
      outputFile.write (reinterpret_cast<const char *> (memory),
                        sizeof (int) * size);
      outputFile.close ();
      std::cout << "Массив успешно записан в файл в бинарном виде."
                << std::endl;
    }
  else
    {
      std::cerr << "Ошибка открытия файла для записи." << std::endl;
      return -1;
    }

  return 0;
}
