//
// Created by Nicolaescu Raoul on 09.05.2023.
//

#ifndef LAB_9_10_FILEREPOSITORY_H
#define LAB_9_10_FILEREPOSITORY_H


#include <fstream>
#include <vector>
#include <string>
#include <iostream>

template <class T> class FileRepository {
public:
    FileRepository();
    FileRepository(const std::string fileName);
    ~FileRepository();
private:
    std::vector<std::vector<T>> undoVec;
    std::vector<T> vector;
    std::string fileName;

public:
    std::vector<T> getAll();
    int getLenght();
    void addElem(const T& elem);
    void updateElem(const T& oldElem, const T& newElem);
    void deleteElem(const T& elem);

    std::string getName() {
        return this->fileName;
    }

    void undo() {
        if (!this->undoVec.empty()) {
            this->vector = this->undoVec.back();
            this->undoVec.pop_back();
            this->saveToFile();
            this->loadFromFile();
            std::cout << "S-A DAT UNDO" << std::endl;
        }
        else
            std::cout << "NU SE MAI POATE DA UNDO" << std::endl;
    }


private:
    void loadFromFile();
    void saveToFile();
};


template<class T> inline FileRepository<T>::FileRepository() {
    this->fileName = "";
};

template<class T> inline FileRepository<T>::FileRepository(const std::string fileName) {
    this->fileName = fileName;
};

template<class T> inline FileRepository<T>::~FileRepository() = default;


template<class T> inline std::vector<T> FileRepository<T>::getAll() {

    if (this->fileName != "")
        this->loadFromFile();

    return this->vector;
}

template<class T> inline int FileRepository<T>::getLenght() {
    if (this->fileName != "")
        this->loadFromFile();

    return this->vector.size();
};


template<class T> inline void FileRepository<T>::addElem(const T& elem) {
    if(this->fileName != "")
        this->loadFromFile();

    this->undoVec.push_back(this->vector);
    this->vector.push_back(elem);


    if(this->fileName != "")
        this->saveToFile();
};

template<class T> inline void FileRepository<T>::updateElem(const T& oldElem, const T& newElem) {
    if (this->fileName != "")
        this->loadFromFile();

    this->undoVec.push_back(this->vector);

    typename std::vector<T>::iterator it;
    it = std::find(this->vector.begin(), this->vector.end(), oldElem);
    if (it != this->vector.end())
    {
        *it = newElem;
    }

    if (this->fileName != "")
        this->saveToFile();


};

template<class T> inline void FileRepository<T>::deleteElem(const T& elem) {

    this->undoVec.push_back(this->vector);

    typename std::vector<T>::iterator it = find(this->vector.begin(), this->vector.end(), elem);
    if (it != this->vector.end()) {
        this->vector.erase(it);
    }

    if (this->fileName != "")
        this->saveToFile();


}


template<class T> void FileRepository<T>::loadFromFile() {
    this->vector.clear();
    if (this->fileName.empty()) {
        std::cout << "The file is empty !!!! \n";
    }
    else {
        std::ifstream file(this->fileName);
        T element;

        while (!file.eof()) {
            file >> element;
            if (!(element == T()))
                this->vector.push_back(element);
        }
        file.close();
    }
};

template<class T> void FileRepository<T>::saveToFile() {
    if (this->fileName.empty()) {
        std::cout << "I can't save to file\n";
    }
    else {
        std::ofstream file(this->fileName);

        for (int i = 0; i < this->vector.size(); i++)
            if (i < this->vector.size() - 1)
                file << this->vector[i] << '\n';
            else
                file << this->vector[i];
        file.close();
    }
};

#endif //LAB_9_10_FILEREPOSITORY_H
