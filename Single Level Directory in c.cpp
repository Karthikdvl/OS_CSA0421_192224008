#include <iostream>
#include <string>
using namespace std;
string root, dirNames[10], fNames[100];
int flag = 0, fCount[10] = {0};
int searchDir(string tempDir){
for (int i = 0; i < flag; i++){
if (dirNames[i] == tempDir)
return i;
}
return -1;
}
int searchFile(string tempFile, int i, int x){
for (int j = i; j < x; j++){
if (dirNames[j] == tempFile)
return j;
}
return -1;
}
void addDir(){
string tempDir;
cout << "Enter the name of the directory to be created:" ;
cin >> tempDir;
int x = searchDir(tempDir);
if (x != -1)
cout << "\nDirectory already exists!\n";
else
dirNames[flag++] = tempDir;
}
void addFile(){
int cv = 1;
string temp;
if (flag == 0){
cout << "\nPlease create a directory first!\n";
return;
}
cout << "Enter the name of the directory inside which the file is to be created: ";
cin >> temp;
int x = searchDir(temp);
int i = x;
if (x == -1){
cout << "\nDirectory does not exist!" << endl;
return;
}
x = x * 10;
x = x + fCount[i];
while (cv){
string tempFile;
cout << "Enter the name of the file to be created inside '" << temp << "': ";
cin >> tempFile;
int y = searchFile(tempFile, i, x);
if (y != -1)
cout << "\nFile already exists!\n";
else{
fNames[x] = tempFile;
fCount[i]++;
}
int tempch;
cout << "\nPress 1 to create more files, Press 0 for Main Menu: ";
cin >> tempch;
cv = tempch;
x++;
}
}
void displayDirTree(){
cout << "\n*********************************************\n";
cout << "\t||USERNAME: “ << root << “||\t\n";
cout << "*********************************************\n";
cout << "\tDIRECTORY\tSIZE\tFILES\n";
cout << "*********************************************\n";
for (int i = 0; i < flag; i++){
cout << "\n\t" << dirNames[i] << "\t\t" << fCount[i] << "\t";
if (fCount[i] == 0)
cout << "NONE\n";
else {
for (int j = i*10; j < fCount[i]+(i*10); j++){
cout << fNames[j] << "\n\t\t\t\t";
}
}
}
cout << "\n*********************************************\n";
}
int main(){
cout << "Enter the User Name: ";
getline(cin, root);
int ch, x = 1;
while (x){
cout << "\nPress 1 to create a directory inside root\n";
cout << "Press 2 to create a file inside a directory\n";
cout << "Press 3 to display the directory tree\n";
cout << "Press 0 to exit\n";
cin >> ch;
switch(ch){
case 0: x = 0;
break;
case 1: addDir();
break;
case 2: addFile();
break;
case 3: displayDirTree();
}
}
return 0;
}
