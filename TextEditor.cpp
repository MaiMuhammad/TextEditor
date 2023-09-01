#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include <iterator>
using namespace std;

string file_name;
int main();
void file(){
    cout<<"Enter File Name as (filename.txt) :";
    cin>>file_name;
    fstream data(file_name);
    if(data.is_open()){
        cout<<endl<<"This File Already Exists."<<endl;
        cout<<endl;
    }else{
        cout<<endl<<"This is a new file . I created it for you."<<endl;
        cout<<endl;
        fstream data(file_name);
    }
}
void empty_file (){
    ofstream data(file_name,ios::trunc);
    cout<<"Now the file is empty."<<endl;
    cout<<endl;
    data.close();
}
void emptyFile (){
    ofstream data(file_name,ios::trunc);
    data.close();
}
void decr_text(){
    fstream data(file_name);
    stringstream Buffer;
    Buffer << data.rdbuf();
    string text_str=Buffer.str();
    string final_text="";
    for (int i=0;i<=text_str.size();i++){
        final_text+=text_str[i]-1;
    }
    emptyFile();
    data<<final_text<<endl;


}
void encr_text(){
    fstream data(file_name);
    stringstream Buffer;
    Buffer << data.rdbuf();
    string text_str=Buffer.str();
    string final_text="";
    for (int i=0;i<=text_str.size();i++){
        final_text+=text_str[i]+1;
    }
    emptyFile();
    data<<final_text<<endl;
}
void save_file(){
    cout<<"DO you want save file?\n1)Yes\n2)No "<<endl;
    int cho;
    cin>>cho;
    if(cho==1){
        cout<<endl;
        cout<<"1)Save in the same file.\n2)Save in new file. "<<endl;
        int cho2;
        cin>>cho2;
        if(cho2==1){
            cout<<endl<<"Done."<<endl;
        }else if(cho2==2){
            string file;
            string line;
            cout<<"Enter new file name as (filename.txt) :";
            cout<<endl;
            cin>>file;
            fstream data;
            data.open(file_name);
            fstream data_copy;
            data_copy.open(file,ios::app);
            if(data.is_open() && data_copy.is_open()){
                cout<<"Done."<<endl;
                while(getline(data,line)){
                    ofstream data(file,ios::trunc);
                    data.close();
                    data_copy << line << "\n";
                }
            }
            else {
                cout<<"cannot read file.";
                cout<<endl;
            }
            data.close();
            data_copy.close();
        }
    }else if(cho==2){
        main();
    }
    else{
        cout<<"Invalid input."<<endl;
        cout<<endl;
        save_file();
    }

}
void display_file(){
    ifstream data(file_name);
    while (!data.eof()) {
        cout << (char)data.get();
    }
    cout<<"\n";
    data.close();
}
void add_text(){
    string text;
    ofstream data(file_name,ios::app);
    cout<<"Enter The Text or Press ctrl+z :";
    while(getline(cin,text)){
        data<<text;
        if(text=="ctrl+z"){
            break;
        }
    } data.close();
    cin.clear();
    main();
}
void times(){
    string word;
    cout<<"Enter the word: ";
    cin>>word;
    ifstream data(file_name);
    int count = 0;
    string search = word;
    string text;
    while (data >> text) {
        if (text == search) {
            ++count;
        }
    }
    cout<< endl<<"The number of times is: "<<count << endl;
}
void UpperCase(){
    fstream data(file_name);
    stringstream Buffer;
    Buffer << data.rdbuf();
    string text=Buffer.str();
    string finalText="";
    for (int i=0;i<= text.size();i++){
        finalText += toupper(text[i]);
    }
    emptyFile();
    data<<finalText<<endl;
}
void LowerCase(){
    fstream data(file_name);
    stringstream Buffer;
    Buffer << data.rdbuf();
    string text=Buffer.str();
    string finalText="";
    for (int i=0;i<= text.size();i++){
        finalText += tolower(text[i]);
    }
    emptyFile();
    data<<finalText<<endl;
}
void firstLetter() {
    fstream data(file_name);
    stringstream Buffer;
    Buffer << data.rdbuf();
    string text = Buffer.str();
    string finalText = "";
    int counter = 0;
    for (int i = 0; i <= text.size(); i++) {
        if (counter == 0) {
            text[i] = toupper(text[i]);
            counter = 1;
        } else if (isspace(text[i]))
            counter = 0;
    }
    emptyFile();
    data<<text<<endl;
}
void Merge_files(){
    char fileOne[500], fileTwo[500], fileTarget[1000], ch;
    fstream fpsOne, fpsTwo, fpTarget;
    cout<<"Enter first file name as (filename.txt) :";
    cin>>fileOne;
    cout<<"Enter second file name as (filename.txt) :";
    cin>>fileTwo;
    fpsOne.open(fileOne, fstream::in);
    fpsTwo.open(fileTwo, fstream::in);
    if((!fpsOne) || (!fpsTwo)){
        cout<<"\nError Occurred (First Source File)!";
    }
    else{
        cout<<"\nEnter the target image file name as (filename.txt) :";
        cin>>fileTarget;
        fpTarget.open(fileTarget, fstream::out);
        if(!fpTarget)
            cout<<"\nError Occurred (Target File)!";
        else
        {
            while(fpsOne >> noskipws >> ch)
                fpTarget << ch;
            fpTarget<<"\n";
            while(fpsTwo >> noskipws >> ch)
                fpTarget << ch;
            cout << "\nContent of Two File Merged Successfully into Third!";
        }
    }
    fpsOne.close();
    fpsTwo.close();
    fpTarget.close();
    cout<<endl;
}
void WordCount() {
    char input[500];
    fstream fps;
    cout <<"Enter File Name as (filename.txt) : ";
    cin>>input;
    fps.open(input, fstream::in);
    ifstream inFile;
    inFile.open(input);
    string line;
    int numlines = 0;
    int numWords = 0;

    while (getline(inFile, line)) {
        numlines++;
        stringstream lineStream(line);
        while (getline(lineStream, line, ' ')) {
            numWords++;
        }
    }
    inFile.close();
    cout << "word count = " << numWords << endl;
}
void lineCount() {
    char input[500];
    fstream fps;
    cout <<"Enter File Name as (filename.txt) : ";
    cin>>input;
    fps.open(input, fstream::in);
    ifstream inFile;
    inFile.open(input);
    string line;
    int numlines = 0;
    int numWords = 0;

    while (getline(inFile, line)) {
        numlines++;
        stringstream lineStream(line);
        while (getline(lineStream, line, ' ')) {
            numWords++;
        }
    }
    inFile.close();
    cout << "line count = " << numlines << endl;
}
void Count_characters(){
    char filename[300], ch;
    int tot=0;
    ifstream fp;
    cout <<"Enter File Name as (filename.txt) : ";
    cin >> filename;
    fp.open(filename, ifstream::in);
    if(!fp){
        cout<<endl<<"File doesn't exist or Access denied!";
    }
    while(fp >> noskipws >> ch)
        tot++;
    fp.close();
    cout << endl<<"Total Characters = "<<tot;
    cout << endl;
}
void search(){
    string word;
    cout<<"Enter the word: ";
    cin>>word;
    ifstream data(file_name);
    int count = 0;
    string search = word;
    string text;
    while (data >> text) {
        if (text == search) {
            ++count;
        }
    }
    if (count!=0){
        cout<< endl<<"Word was found in the file."<< endl;
    }
    else if(count==0){
        cout<< endl<<"Word was not found in the file."<< endl;
    }
}
int main(){
    int choose;
    cout<<"----------------Menu----------------"<<endl;
    cout<<"1) Add new text.\n2) Display content of the file.\n3) Empty the file.\n"
          "4) Encrypt text.\n5) Decrypt text.\n6) Merge another file.\n7) Count the number of words in the file.\n"
          "8) Count the number of characters in the file.\n9) Count the number of lines in the file.\n"
          "10) Search for a word in the file.\n11) Count the number of times a word exists in the file.\n"
          "12) Turn the file content to upper case.\n13) Turn the file content to lower case.\n"
          "14) Turn file content to 1st caps.\n15) Save.\n16) Exit."<<endl;
    cout<<"Enter Number From Menu :";
    cin>>choose;
    switch (choose) {
        case 1:
            file();
            add_text();
        case 2:
            file();
            display_file();
            main();
        case 3:
            file();
            empty_file();
            main();
        case 4:
            file();
            encr_text();
            save_file();
            main();
        case 5:
            file();
            decr_text();
            save_file();
            main();
        case 6:
            Merge_files();
            main();
        case 7:
            WordCount();
            main();
        case 8:
            Count_characters();
            main();
        case 9:
            lineCount();
            main();
        case 10:
            file();
            search();
        case 11:
            file();
            times();
            main();
        case 12:
            file();
            UpperCase();
            cout<<"Done."<<endl;
            main();
        case 13:
            file();
            LowerCase();
            cout<<"Done."<<endl;
            main();
        case 14:
            file();
            firstLetter();
            cout<<"Done."<<endl;
            main();
        case 15:
            file();
            save_file();
            main();
        case 16:
            cout<<"Thanks for using our App."<<endl;
            break;
        default:
            cout<<"Invalid input."<<endl;
            main();
    }
}
