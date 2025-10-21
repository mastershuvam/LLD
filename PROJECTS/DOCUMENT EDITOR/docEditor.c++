#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
using namespace std;


// Interface: DocumentElement

class DocumentElement {
public:
    virtual string render() const = 0;
    virtual ~DocumentElement() {}
};


// Concrete Elements

class TextElement : public DocumentElement {
    string text;
public:
    TextElement(const string& text) : text(text) {}
    string render() const override { return text; }
};

class ImageElement : public DocumentElement {
    string imageName;
public:
    ImageElement(const string& imageName) : imageName(imageName) {}
    string render() const override { return "[Image: " + imageName + "]"; }
};

class NewLineElement : public DocumentElement {
public:
    string render() const override { return "\n"; }
};

class TabSpaceElement : public DocumentElement {
public:
    string render() const override { return "\t"; }
};


// Class: Document (Single Responsibility)

class Document {
    vector<shared_ptr<DocumentElement>> elements;
public:
    void addElement(shared_ptr<DocumentElement> element) {
        elements.push_back(element);
    }

    string render() const {
        string output;
        for (const auto& e : elements) output += e->render();
        return output;
    }
};


// Interface: Persistence (Dependency Inversion)

class Persistence {
public:
    virtual void save(const string& data) = 0;
    virtual ~Persistence() {}
};


// Class: FileStorage (Open-Closed Principle)

class FileStorage : public Persistence {
public:
    void save(const string& data) override {
        ofstream out("document.txt");
        if (out) {
            out << data;
            cout << " Document saved to document.txt\n";
        } else {
            cerr << " Error: Unable to save file.\n";
        }
    }
};


// Class: DocumentEditor (High-level module)

class DocumentEditor {
    shared_ptr<Document> document;
    shared_ptr<Persistence> storage;
public:
    DocumentEditor(shared_ptr<Document> doc, shared_ptr<Persistence> store)
        : document(doc), storage(store) {}

    void addText(const string& text) { document->addElement(make_shared<TextElement>(text)); }
    void addImage(const string& image) { document->addElement(make_shared<ImageElement>(image)); }
    void addNewLine() { document->addElement(make_shared<NewLineElement>()); }
    void addTabSpace() { document->addElement(make_shared<TabSpaceElement>()); }

    string renderDocument() const { return document->render(); }
    void saveDocument() { storage->save(renderDocument()); }
};


// MAIN: User Input + Demo

int main() {
    auto document = make_shared<Document>();
    auto storage = make_shared<FileStorage>();
    DocumentEditor editor(document, storage);

    cout << "=== Document Editor ===\n";
    cout << "Options:\n"
         << "1. Add Text\n"
         << "2. Add Image\n"
         << "3. Add New Line\n"
         << "4. Add Tab Space\n"
         << "5. Show Document\n"
         << "6. Save Document\n"
         << "0. Exit\n";

    int choice;
    do {
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string text;
                cout << "Enter text: ";
                getline(cin, text);
                editor.addText(text);
                break;
            }
            case 2: {
                string image;
                cout << "Enter image name: ";
                getline(cin, image);
                editor.addImage(image);
                break;
            }
            case 3:
                editor.addNewLine();
                break;
            case 4:
                editor.addTabSpace();
                break;
            case 5:
                cout << "\n--- Document Preview ---\n";
                cout << editor.renderDocument() << endl;
                break;
            case 6:
                editor.saveDocument();
                break;
            case 0:
                cout << "Exiting editor...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
