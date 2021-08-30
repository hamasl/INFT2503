#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(){

    //Task a
    string word1;
    string word2;
    string word3;
    cout << "Enter word1: " << endl;
    cin >> word1;
    cout << "Enter word2: " << endl;
    cin >> word2;
    cout << "Enter word3: " << endl;
    cin >> word3;

    //Task b
    string sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << "Sentence is: " << sentence << endl;

    //Task c
    cout << "Length of word1: " << word1.length() << endl;
    cout << "Length of word2: " << word2.length() << endl;
    cout << "Length of word3: " << word3.length() << endl;
    cout << "Length of sentence: " << sentence.length() << endl;

    //Task d
    //This is technically a copy since C++ copies it for ous, instead of manually needing to copy each character
    string sentence2 = sentence;

    //Task e
    //Using unsigned long since sentence2.length() returns that
    for (unsigned long i = 10; i < 13; ++i) {
        if(sentence2.length() >= i) {
            sentence2[i] = 'x';
        }
    }

    cout << "sentence: " << sentence << endl;
    cout << "sentence2: " << sentence2 << endl;

    //Task f
    string sentence_start = sentence.substr(0, (sentence.length() < 5) ? sentence.length() : 5);
    cout << "sentence: " << sentence << endl;
    cout << "sentence_start: " << sentence_start << endl;

    //Task g
    const string search_word = "hallo";
    size_t found_at = sentence.find(search_word);

    if(found_at != string::npos){
        cout << "sentence includes word '" << search_word << "' at start index: " << found_at << endl;
    } else{
        cout << "sentence does not include word '" << search_word << "'" << endl;
    }

    //Task h
    vector<size_t> occurences;
    const string search_word_v2 = "er";
    size_t start_index = 0;
    bool keep_going = true;
    while (start_index < sentence.length() && keep_going){
        //Reusing found_at from task g
        found_at = sentence.find(search_word_v2, start_index);
        if(found_at != string::npos){
            occurences.push_back(found_at);
            start_index = found_at + search_word_v2.length();
        } else{
            keep_going = false;
        }
    }
    if(occurences.empty()){
        cout << "sentence does not have any occurences of '" << search_word_v2 << "'";
    } else{
        cout << "sentence has " << occurences.size() << " of '" << search_word_v2 << "' with start indexes located at:" << endl;
        for (auto occurence : occurences) {
            cout << occurence << endl;
        }
    }

    return 0;
}

