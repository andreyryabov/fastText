//
// Created by Andrey Ryabov on 3/25/20.
//
#include <fasttext.h>
#include <iostream>

using namespace std;
using namespace fasttext;


int main() {
    auto fileName = "/Users/andreyryabov/.__nlp_cache__/blob_cache/alan-models/fastTest-word-vectors/cc.en.300.bin.gz/cc.en.300.bin";
    auto inFile = ifstream(fileName, ios::binary);
    inFile.seekg(0, std::ios::end);
    auto fileSize = inFile.tellg();
    inFile.seekg(0);

    vector<char> data(fileSize);
    inFile.read(&data[0], data.size());
    MemStream mm(&data[0], data.size());

    cout<<"File size: "<<fileSize<<endl;

    FastText fastText;
    if (!fastText.checkModel(mm)) {
        throw invalid_argument(fileName + " has wrong file format!"s);
    }

    fastText.loadModel(mm);
    Vector v(fastText.getDimension());
    fastText.getWordVector(v, "hello");

    cout<<"Vector size: "<<v.size()<<endl;
    for (int i = 0; i < v.size(); i++ ) {
        cout<<v[i]<<endl;
    }

    return 0;
}