void savex123()
{
    system("dir /s /b C:\\*.* > exodus.txt");
    std::cout << "Save -> 'exodus.txt'.\n";
}

void savex532()
{
    std::ifstream originalFile("exodus.txt");
    std::vector<std::string> originalDlls;
    std::string line;
    while (std::getline(originalFile, line))
    {
        originalDlls.push_back(line);
    }
    originalFile.close();

    system("dir /s /b C:\\*.* > exodus_new.txt");

    std::ifstream newFile("exodus_new.txt");
    std::vector<std::string> newDlls;
    while (std::getline(newFile, line))
    {
        newDlls.push_back(line);
    }
    newFile.close();

    for (const auto& newDll : newDlls)
    {
        bool found = false;
        for (const auto& originalDll : originalDlls)
        {
            if (newDll == originalDll)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            std::cout << "\033[31mMatch\033[0m -> " << "newDll" << "\n";

            struct stat fileInfo;
            if (stat(newDll.c_str(), &fileInfo) == 0)
            {
                std::cout << "Path -> " << newDll << "\n";
                std::cout << "Size -> " << fileInfo.st_size << " bytes\n";
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
        std::cout << "[1] Ferst step\n";
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
            savex532();
            break;
        case 3:
            std::cout << "Exit Succes...\n";
            return;
        default:
            std::cout << "Error only numers inside brackets.\n";
        }
        std::cout << "Press enter key to continue...";
        std::cin.ignore();
        std::cin.get();
        system("cls");
    }
}

void subx25356()
{
        std::cout << "7exodus Private Acces\n";
        system("color 1");
        system("timeout /t 3");
        system("cls");
        subx9873();

}