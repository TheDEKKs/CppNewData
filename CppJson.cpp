#include <iostream>
#include <fstream> 
#include <iostream> 
#include <string>
#include "include/rapidjson/document.h" 
#include "include/rapidjson/filereadstream.h" 


using namespace rapidjson; 
std::string Data;

class NewData{
       
    public:
        int ReadNewData(const char* name) {
            FILE* fp = fopen(name, "r"); 
            char readBuffer[65536]; 
            rapidjson::FileReadStream is(fp, readBuffer, 
                                        sizeof(readBuffer)); 
        
            // Parse the JSON data  
            // using a Document object 
            rapidjson::Document d; 
            d.ParseStream(is); 
        
            // Close the file 
            fclose(fp); 

            if (d["BackData"].GetString() != d["NewData"].GetString()){
                Data = d["NewData"].GetString();
            }
        
            // Access the data in the JSON document 
            std::cout << Data << std::endl; 
            
            return 0;
        }
};



int main(){
    NewData obj;
    obj.ReadNewData("data.json");
    return 0;
    
}





