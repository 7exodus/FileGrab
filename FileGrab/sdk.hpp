void savex123()
{
    std::cout << "Wait...\n";
    system("dir /s /b C:\\*.* > exodus.txt");
    std::cout << "Save -> 'exodus.txt'.\n";
}

void savex532()
{
    std::cout << "Wait...\n";
    std::ifstream originalFile("exodus.txt");
    std::vector<std::string> originalFiles;
    std::string line;
    while (std::getline(originalFile, line))
    {
        originalFiles.push_back(line);
    }
    originalFile.close();

    system("dir /s /b C:\\*.* > exodus_new.txt");

    std::ifstream newFile("exodus_new.txt");
    std::vector<std::string> newFiles;
    while (std::getline(newFile, line))
    {
        newFiles.push_back(line);
    }
    newFile.close();

    for (const auto& newFile : newFiles)
    {
        bool found = false;
        for (const auto& originalFile : originalFiles)
        {
            if (newFile == originalFile)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            // Extraer la extensión del archivo
            size_t dotPos = newFile.find_last_of(".");
            std::string extension = (dotPos != std::string::npos) ? newFile.substr(dotPos + 1) : "unknown";

            std::cout << "\033[31mWARNING !\033[0m" << "\n";

            struct stat fileInfo;
            if (stat(newFile.c_str(), &fileInfo) == 0)
            {
                std::cout << "Path -> " << newFile << "\n";
                std::cout << "Size -> " << fileInfo.st_size << " bytes\n";
                std::cout << "Extension -> " << extension << "\n";
            }
            else
            {
                std::cerr << "Error -> Size.\n";
            }
        }
    }
}

void subx9873()
{
    int choice;
    while (true)
    {
        system("color 1");
        std::cout << "[1] First step\n";
        std::cout << "[2] Second step\n";
        std::cout << "[3] Exit\n";
        std::cout << "Set your choice -> ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            savex123();
            break;
        case 2:
            system("cls");
            savex532();
            break;
        case 3:
            std::cout << "Exit Success...\n";
            return;
        default:
            std::cout << "Error: only numbers inside brackets.\n";
        }
        std::cout << "Press enter key to continue...";
        std::cin.ignore();
        std::cin.get();
        system("cls");
    }
}

void subx25356()
{
    std::cout << "7exodus\n";
    system("color 1");
    system("timeout /t 3");
    system("cls");
    subx9873();
}