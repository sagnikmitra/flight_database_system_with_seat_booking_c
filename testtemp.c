#include <stdio.h>
int main()
{
    if (remove("TestTemp2.txt") == 0)
    {
        printf("File deleted successfully");
    }
    else
    {
        printf("Could not delete file");
    }; // remove the original file
    char old_name[] = "bbbb.txt";
    char new_name[] = "TestTemp2.txt";
    int value;
    value = rename(old_name, new_name);
    if (!value)
    {
        printf("%s", "File name changed successfully");
    }
    else
    {
        perror("Error");
    }
    return 0;
}