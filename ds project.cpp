#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> 
#include <ctime>
#include<fstream>
#include<string.h>
#include<windows.h>


using namespace std;

class DigitalLibrary;
class Hashing;
const int size=100;
void login();
void Registration();
void Menu();
int hashfunction(string a);
string crypt(char choice, string a);


class fvrt
{
public:
    string title;
    string author;
    string genre;
    double rating;
    int priority;

 
};



class BookNode {
	public:
	 string title;
    string author;
    string genre;
    double rating;
   
    BookNode* next;
    BookNode* prev;

    BookNode(string title,string author,string genre, double rating)  {
	  this->title=title;
	  this->author=author;
	  this->genre=genre;
	  this->rating =rating;
	  next=NULL;
      prev=NULL;
	}
};

class BookList {

public:
    BookNode* head;
    BookNode* tail;
    fvrt *suggested;
    int bookNum;

public:
    BookList() : head(NULL),tail(NULL) {
    	suggested=new fvrt[3];
        // Generate 100 sample books during initialization
addBook("Life of Pi", "Y. Martel", "Adventure", 4.1);
addBook("Dune", "F. Herbert", "Science Fiction", 4.5);
addBook("Brave New World", "A. Huxley", "Dystopian", 4.0);
addBook("Siddhartha", "H. Hesse", "Historical Fiction", 4.2);
addBook("Fahrenheit 451", "R. Bradbury", "Dystopian", 4.3);
addBook("Candide", "V. Hugo", "Satire", 4.1);
addBook("Neuromancer", "W. Gibson", "Science Fiction", 4.4);
addBook("Snow Crash", "N. Stephenson", "Science Fiction", 4.0);
addBook("Mistborn", "B. Sanderson", "Fantasy", 4.6);
addBook("Oryx and Crake", "M. Atwood", "Dystopian", 4.2);
addBook("The Martian", "A. Weir", "Science Fiction", 4.7);
addBook("The Hitchhiker's Guide", "D. Adams", "Science Fiction", 4.6);
addBook("The Hunger Games", "S. Collins", "Dystopian", 4.3);
addBook("The Fault in Our Stars", "J. Green", "Romance", 4.3);
addBook("Ender's Game", "O. Scott Card", "Science Fiction", 4.5);
addBook("Divergent", "V. Roth", "Dystopian", 4.1);
addBook("Catcher in the Rye", "J.D. Salinger", "Adventure", 4.1);
addBook("One Hundred Years of Solitude", "G.G. Márquez", "Thriller", 4.4);
addBook("The Shining", "S. King", "Horror", 4.2);
addBook("Picture of Dorian Gray", "O. Wilde", "Gothic Fiction", 4.0);
addBook("Old Man and the Sea", "E. Hemingway", "Adventure", 4.1);
addBook("The Jungle", "U. Sinclair", "Social Fiction", 4.0);
addBook("Da Vinci Code", "D. Brown", "Mystery", 4.0);
addBook("Girl with the Dragon Tattoo", "S. Larsson", "Mystery", 4.1);
addBook("Alchemist", "P. Coelho", "Adventure", 4.2);
addBook("Wuthering Heights", "E. Brontë", "Historical Fiction", 4.1);
addBook("The Road", "C. McCarthy", "Horror", 4.1);
addBook("Anna Karenina", "L. Tolstoy", "Historical Fiction", 4.1);
addBook("Count of Monte Cristo", "A. Dumas", "Adventure", 4.5);
addBook("Maze Runner", "J. Dashner", "Dystopian", 4.0);
addBook("The Help", "K. Stockett", "Historical Fiction", 4.2);
addBook("Sun Also Rises", "E. Hemingway", "Dystopian", 4.0);
addBook("Les Misérables", "V. Hugo", "Historical Fiction", 4.5);
addBook("Brothers Karamazov", "F. Dostoevsky", "Historical Fiction", 4.4);
addBook("Crime and Punishment", "F. Dostoevsky", "Historical Fiction", 4.3);
addBook("The Stand", "S. King", "Thriller", 4.4);
addBook("Girl on the Train", "P. Hawkins", "Thriller", 4.0);
addBook("Silence of the Lambs", "T. Harris", "Thriller", 4.5);
addBook("Gone Girl", "G. Flynn", "Mystery", 4.1);
addBook("Pride and Prejudice", "J. Austen", "Romance", 4.4);
addBook("Jane Eyre", "C. Brontë", "Non-Fiction", 4.3);
addBook("Iliad", "Homer", "Epic Poetry", 4.4);
addBook("Odyssey", "Homer", "Epic Poetry", 4.5);
addBook("Book Thief", "M. Zusak", "Historical Fiction", 4.3);
addBook("Great Expectations", "C. Dickens", "Mystery", 4.2);
addBook("Dracula", "B. Stoker", "Horror", 4.0);
addBook("Grapes of Wrath", "J. Steinbeck", "Historical Fiction", 4.0);
addBook("In Cold Blood", "T. Capote", "Romance", 4.3);

bookNum=48;




        // ... add more books ...
    }

    void addBook(string title,string author,string genre,double rating) {
    	BookNode*temp=new BookNode(title,author,genre,rating);
        if(head==NULL){
        	head=temp;
        	tail=temp;
        	tail->next=NULL;
        	temp->prev=NULL;
		}
		else{	

			temp->prev=tail;
			tail->next=temp;
			tail=tail->next;
			tail->next=NULL;
			
		}
		bookNum++;
    }
    
     void removeBookByNumber(int bookNumber) {
        int currentNumber = 1;
        BookNode* current = head;

        while (current != nullptr) {
            if (currentNumber == bookNumber) {
                if (current->prev != nullptr) {
                    // Update the previous node's next pointer
                    current->prev->next = current->next;
                } else {
                    // If the removed node is the head, update the head
                    head = current->next;
                }

                if (current->next != nullptr) {
                    // Update the next node's previous pointer
                    current->next->prev = current->prev;
                } else {
                    // If the removed node is the tail, update the tail
                    tail = current->prev;
                }

                // Free the memory occupied by the removed node
                delete current;
                std::cout << "Book removed at position " << bookNumber << std::endl;
                return;
            }

            // Move to the next node
            current = current->next;
            currentNumber++;
        }

        cout << "Invalid book number: " << bookNumber << std::endl;
    }
    
    void RandomSuggestion(){
    srand(static_cast<unsigned int>(time(nullptr)));
       int number = 0+rand()%bookNum;
       BookNode*temp=head;
       for(int i=0;i<number;i++){
       	temp=temp->next;
       	
	   }
	    cout << "Title: " << temp->title << "\tAuthor: " << temp->author << "\tGenre: " << temp->genre << "\tRating: " << temp->rating<< endl;
	   
       
	}

     


void displayBooks() const {
    if (!head) {
        cout << "No books available.\n";
        return;
    }

    int rowNum = 1; // Starting row number

    // Print header
    cout << setw(4) << "Row" << setw(30) << "Title" << setw(20) << "Author" << setw(15) << "Genre" << setw(10) << "Rating" << endl;
    cout << "==============================================================\n";

    // Traverse the linked list and print each book
    BookNode* current = head;
    while (current!=NULL) {
        cout << setw(4) << rowNum << setw(30) << current->title.substr(0, 27) << "..." // Adjusted for long titles
             << setw(20) << current->author << setw(15) << current->genre << setw(10) << current->rating << endl;

        current = current->next;
        ++rowNum;
    }
}



     BookNode* PartitionBytitle(BookNode* start, BookNode* end) {
        string pivot = end->title;
        BookNode* pindex = start;
        BookNode* temp = start;
        while (temp != end) {
            if (temp->title < pivot) {
                swap(temp->title, pindex->title);
                swap(temp->author, pindex->author);
                swap(temp->genre, pindex->genre);
                swap(temp->rating, pindex->rating);
                pindex = pindex->next;
            }
            temp = temp->next;
        }

        swap(end->title, pindex->title);
        swap(end->author, pindex->author);
        swap(end->genre, pindex->genre);
        swap(end->rating, pindex->rating);
        return pindex;
    }

    void sortByTitle(BookNode* start, BookNode* end) {
        if (start != nullptr && end != nullptr && start != end && start != end->next) {
            BookNode* loc = PartitionBytitle (start, end);
            sortByTitle(start, loc->prev);
            sortByTitle(loc->next, end);
        }
    }


    BookNode* PartitionByGenre(BookNode* start, BookNode* end) {
        string pivot = end->genre;
        BookNode* pindex = start;
        BookNode* temp = start;
        while (temp != end) {
            if (temp->genre < pivot) {
                swap(temp->title, pindex->title);
                swap(temp->author, pindex->author);
                swap(temp->genre, pindex->genre);
                swap(temp->rating, pindex->rating);
                pindex = pindex->next;
            }
            temp = temp->next;
        }

        swap(end->title, pindex->title);
        swap(end->author, pindex->author);
        swap(end->genre, pindex->genre);
        swap(end->rating, pindex->rating);
        return pindex;
    }

    void sortByGenre(BookNode* start, BookNode* end) {
        if (start != nullptr && end != nullptr && start != end && start != end->next) {
            BookNode* loc =  PartitionByGenre (start, end);
             sortByGenre(start, loc->prev);
             sortByGenre(loc->next, end);
        }
    }

 BookNode* PartitionByRating(BookNode* start, BookNode* end) {
        double pivot = end->rating;
        BookNode* pindex = start;
        BookNode* temp = start;
        while (temp != end) {
            if (temp->rating < pivot) {
                swap(temp->title, pindex->title);
                swap(temp->author, pindex->author);
                swap(temp->genre, pindex->genre);
                swap(temp->rating, pindex->rating);
                pindex = pindex->next;
            }
            temp = temp->next;
        }

        swap(end->title, pindex->title);
        swap(end->author, pindex->author);
        swap(end->genre, pindex->genre);
        swap(end->rating, pindex->rating);
        return pindex;
    }

    void sortByRating(BookNode* start, BookNode* end) {
        if (start != nullptr && end != nullptr && start != end && start != end->next) {
            BookNode* loc =  PartitionByRating (start, end);
            sortByRating(start, loc->prev);
            sortByRating(loc->next, end);
        }
    }

    BookNode* getMiddle(BookNode* start, BookNode* end) {
    if (start == nullptr)
        return nullptr;

    BookNode* slow = start;
    BookNode* fast = start->next;

    while (fast != end && fast != nullptr) {
        fast = fast->next;
        if (fast != end && fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}
BookNode* binarySearch(BookNode* start, BookNode* end, string title) {
    if (start == nullptr || end == nullptr)
        return nullptr;

    while (start != end && start->prev != end) {
       BookNode* mid = getMiddle(start, end);

        if (mid->title == title)
            return mid;
        else if (mid->title < title)
            start = mid->next;
        else
            end = mid->prev;
    }

    if (start != nullptr && start->title == title)
        return start;

    return nullptr;
}

void suggestBook(string genre) {
    int i = 0;
    BookNode* temp = head;

    while (temp != nullptr && i < 3) {
        if (temp->genre == genre) {
            suggested[i].author = temp->author;
            suggested[i].genre = temp->genre;
            suggested[i].rating = temp->rating;
            suggested[i].title = temp->title;
            i++;
        }
        temp = temp->next;
    }

    for (int i = 0; i < 3; i++) {
        cout << "Title: " << suggested[i].title << "\tAuthor: " << suggested[i].author << "\tGenre: " << suggested[i].genre << "\tRating: " << suggested[i].rating << endl;
    }
}


 

};



class Preference{
	public:
	int count;
	string genre;
	Preference(){
		count=0;
	}
};


class AddToFavoriteByPriority
{
public:
    int front;
    int rear;
    int i;
    BookList books;
    Preference *preference;
    fvrt *arr;
     
    AddToFavoriteByPriority()
    {
        front = -1;
        rear = -1;
        i = 0;
        
        arr = new fvrt[size];
        preference=new Preference[10];
       
        for (int i = 0; i < 10; i++)
        {
            preference[i].count=0;
        }
        preference[0].genre="Science Fiction";
        preference[1].genre="Fantasy";
        preference[2].genre="Romance";
        preference[3].genre="horror";
        preference[4].genre="Adventure";
        preference[5].genre="Dystopian";
        preference[6].genre="Thriller";
        preference[7].genre="Non-Fiction";
        preference[8].genre="Historical Fiction";
        preference[9].genre="Mystery";
        enqueue(3,7);
        enqueue(6,2);
        enqueue(2,5);
        enqueue(9,8);
        enqueue(21,3);
        enqueue(11,9);
        enqueue(13,6);
        enqueue(31,1);
        
    }
    
    
    
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (size - 1 == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    fvrt dequeue()
    {
        if (isEmpty())
        {
            cout << "stack is empty,underflow" << endl;
        }
        cout << arr[front].title << "is removed form the list" << endl;
        return arr[front++];
    }
    void enqueue(int num, int priority){
        if (isFull())
        {
            cout << "Maximum capacity reached " << endl;
            return;
        }
        BookNode* temp=books.head;
        for(int i=1;i<num;i++){
        	temp=temp->next;
		}

        fvrt newBook;
        newBook.title = temp->title;
        newBook.author = temp->author;
        newBook.genre = temp->genre;
        newBook.rating = temp->rating;
        newBook.priority = priority;

        if (isEmpty())
        {
            front = 0;
            rear = 0;
            arr[rear] = newBook;
            cout << "Book inserted in favorite list according to the priority" << endl;
            return;
        }

        int position = rear;
        while (position >= 0 && priority < arr[position].priority)
        {
            arr[position + 1] = arr[position];
            position--;
        }

        arr[position + 1] = newBook;
        rear++;
        cout << "Book inserted in favorite list according to the priority" << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = front; i <= rear; i++)
        {
            cout << "Title: " << arr[i].title << "\tAuthor: " << arr[i].author << "\tGenre: " << arr[i].genre << "\tRating: " << arr[i].rating << "\tPriority: " << arr[i].priority << endl;
        }
    }
    
  string suggestionByGenre(){
 	    
       for (int i = 0; i < 10; i++)
       {
           for (int j = 0; j < 10; j++)
           {
                if(preference[i].genre==arr[j].genre)
                {
                    preference[i].count++;
                }
           }
           
       }
            int max=0;
            int maxIndex=0;
       for (int i = 0; i < 10; i++)
       {
           if(preference[i].count>max)
           {
            max=preference[i].count;
            maxIndex=i;
           }
       }
       
	        string result=arr[maxIndex].genre;
            return result;
	}
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

class DigitalLibrary {
private:
    BookList bookList;

    AddToFavoriteByPriority favoritesList;
    BookNode*searched;

public:
    DigitalLibrary() {
        
    }

    void displayMenu() {
    	 string title,author,genre,search,fvrt;
         double rating;
         int num,priority,bookNum,sug;
        int choice;

        do {
            clearScreen(); // Clear the screen before displaying the menu

        	cout << "\t\t\t_________________________________________________________\n\n";
            cout << "\t\t\t                 DIGITAL LIBRARY MENU                    \n";
        	cout << "\t\t\t_________________________________________________________\n\n";
            cout << "\t\t\t| 1. Display All Books             |\n";
            cout << "\t\t\t| 2. Search for a Book             |\n";
            cout << "\t\t\t| 3. Add a New Book                |\n";
            cout << "\t\t\t| 4. Remove a Book                 |\n";
            cout << "\t\t\t| 5. Sort Books                    |\n";
            cout << "\t\t\t| 6. Display Favorites             |\n";
            cout << "\t\t\t| 7. Add to Favorites              |\n";
            cout << "\t\t\t| 8. Remove from Favorites         |\n";
            cout << "\t\t\t| 9. Suggest me a Book             |\n";
            cout << "\t\t\t| 10. Exit\n";
       		cout << "\t\t\t_________________________________________________________\n";

            cout << "\t\t\tEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    clearScreen();
                    bookList.displayBooks();
                    waitForReturnToMenu();
                    break;
                case 2:
                    clearScreen();
                    fflush(stdin);
                    bookList.sortByTitle(bookList.head,bookList.tail);
                    cout<<"Enter the title of the book you want to search"<<endl;
                    getline(cin,search);

                   searched=bookList.binarySearch(bookList.head,bookList.tail,search);
                     if(searched!=nullptr){
                         cout << "Title: " << searched->title << "\tAuthor: " << searched->author << "\tGenre: " << searched->genre << "\tRating: " << searched->rating<<endl;
						 }
                    else{
                       cout<<"value not found"<<endl;
					   
					   }
                    waitForReturnToMenu();
                    break;
                case 3:
                    	
                    clearScreen();
                   fflush(stdin);
                    cout<<"Enter the title of Book"<<endl;
                    getline(cin,title);
                    cout<<"Enter the author of Book"<<endl;
                    getline(cin,author);
                    cout<<"Enter the genre of Book"<<endl;
                   getline(cin,genre);
                    cout<<"Enter the rating of Book"<<endl;
                    cin>>rating;
                    bookList.addBook(title,author,genre,rating);
                    cout<<"Book added Sucessfully";
                    
                    waitForReturnToMenu();
                    break;
                   case 4:
                   clearScreen();
                  bookList.displayBooks();
                  
                   cout<<"Enter the number of book you want to remove"<<endl;
                   cin>>bookNum;
                 
                  bookList.removeBookByNumber(bookNum);
                  waitForReturnToMenu();
                 break;

                case 5:
                    clearScreen();
                    displaySortSubMenu();
                    waitForReturnToMenu();
                    break;
                case 6:
                    clearScreen();
                    favoritesList.display();
                    waitForReturnToMenu();
                    break;
                case 7:
                    clearScreen();
                    bookList.displayBooks();
                    cout<<"Enter the book number you want to add in favorite"<<endl;
                    cin>>num;
                    cout<<"Enter the priority of this book out of 10"<<endl;
                    cin>>priority;
                    favoritesList.enqueue(num,priority);
                    waitForReturnToMenu();
                    break;
                case 8:
                    clearScreen();
                    favoritesList.dequeue();
                    waitForReturnToMenu();
                    break;
                case 9:
                	clearScreen();
                	cout<<"1) Suggestion by Genere"<<endl;
                	cout<<"2) Random Suggestion"<<endl;
                	cin>>sug;
                	if(sug==1){
                    fvrt=favoritesList.suggestionByGenre();
                    bookList.suggestBook(fvrt);
					}
					else if(sug==2){
                	bookList.RandomSuggestion();
					}
					else{
						cout<<"Invalid input"<<endl;
					}
					waitForReturnToMenu();
                	break;
                case 10:
                    cout << "Exiting. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    waitForReturnToMenu();
            }

        } while (choice != 10);
    }

    // Function to wait for user input to return to the menu
    void waitForReturnToMenu() {
        cout << "\nPress Enter to return to the menu...";
        cin.ignore(); // Clear the input buffer
        cin.get();    // Wait for Enter key press
    }
    
    void displaySortSubMenu() {
    int sortChoice;

    do {
        clearScreen();
        cout << "\t\t\t_________________________________________________________\n\n";
        cout << "\t\t\t                       SORT SUBMENU                      \n";
        cout << "\t\t\t_________________________________________________________\n\n";
        cout << "\t\t\t| 1. Sort by Title                |\n";
        cout << "\t\t\t| 2. Sort by Genre                |\n";
        cout << "\t\t\t| 3. Sort by Rating               |\n";
        cout << "\t\t\t| 4. Back to Main Menu            |\n\n";
        cout << "\t\t\t_________________________________________________________\n";

        cout << "\t\t\tEnter your choice: ";
        cin >> sortChoice;

        switch (sortChoice) {
            case 1:
                clearScreen();
                bookList.sortByTitle(bookList.head, bookList.tail);
                bookList.displayBooks();
                cout << "Books sorted by title.\n";
                waitForReturnToMenu();
                break;
            case 2:
                clearScreen();
                bookList.sortByGenre(bookList.head, bookList.tail);
                  bookList.displayBooks();
                cout << "Books sorted by genre.\n";
                waitForReturnToMenu();
                break;
            case 3:
                clearScreen();
                bookList.sortByRating(bookList.head, bookList.tail);
                  bookList.displayBooks();
                cout << "Books sorted by rating.\n";
                waitForReturnToMenu();
                break;
            case 4:
                // Return to the main menu
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                waitForReturnToMenu();
        }

    } while (sortChoice != 4);
}
};



class Hashing{
public:
    string *arr;
    int size;

    Hashing(int size) {
        this->size = size;
        arr = new string[size];
        for (int i = 0; i < size; i++) {
            arr[i] = " ";
        }
    }

    int hashFunction(string a) {
        int sum = 0;
        for (int i = 0; i < a.length(); i++) {
            sum += a[i];
        }
        return sum % size;
    }

    void Insert(string key) {
    	ReadFromFile();
        int index = hashFunction(key);
        if (arr[index] == " ") {
            arr[index] = key;
            WriteToFile();  
        } 
		else {
            int i = 1;
            while (arr[(index + i) % size] != " ") {
                i++;
            }
            arr[(index + i) % size] = key;
            WriteToFile(); 
        }
    }

    void WriteToFile() {
        ofstream outputFile("record.txt");

        if (!outputFile.is_open()) {
            cout << "Error opening the file for writing.\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            outputFile << arr[i] << '\n';
        }
        outputFile.close();
    }

    void ReadFromFile() {
        ifstream inputFile("record.txt");

        if (!inputFile.is_open()) {
            cout << "Error opening the file for reading.\n";
            return;
        }

        for (int i = 0; i < size; i++) {
            getline(inputFile, arr[i]);
        }

        inputFile.close();
    }
    
	bool search(string key){
		ReadFromFile();
        int index = hashFunction(key);
        int repeat = index;
        if(arr[index] == key){
            return true;
        }
        else{
            while(arr[index + 1] != key){
                index++;
                if (index == size){
                    index = 0;
                }
                if (index == repeat){
                    return false;
                }
            }
            return true;
        }
    }
};
Hashing h(100);

void Menu(){
	int c;
	cout<<"\t\t\t_________________________________________________________\n\n\n";
	cout<<"\t\t\t                  Welcome to the login page             \n\n";
	cout<<"\t\t\t_________________           MENU        __________________\n\n";
	cout<<"\t\t\t| Press 1 to LOGIN           |"<<endl;
	cout<<"\t\t\t| Press 2 to REGISTER        |"<<endl;
	cout<<"\t\t\t| Press 3 to EXIT            |\n\n";
	cout << "\t\t\t_________________________________________________________\n";

	cout<<"\n\t\t\t Please Enter your choice : ";
	cin>>c;
	cout<<endl;
	switch(c){
		case 1:
			login();
			break;
			
		case 2:
			Registration();
			break;
			
		case 3:
			cout<<"\t\t\t ThankYou! \n\n";
			break;
			
		default:
			system("cls");
			cout<<"\t\t\t Please select from the options given about"<<endl;		
	}
}

void login() {
    bool count = false;
    string userID, password, id, pass;
    system("cls");
    cout << "\t\t\t Please Enter the Username and Password : " << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userID;
    cout << "\t\t\t PASSWORD ";
    cin >> password;
    string str1 = userID + " " + password;
    str1 = crypt('e',str1);
    ifstream input("record.txt");
	count =	h.search(str1);

    if (count == true) {
        cout << userID << "\n Your LOGIN is successful \n Thanks for logging in ! \n";
        sleep(3
		);
        DigitalLibrary library;
    	library.displayMenu();
    } 
	else {
        cout << "\n LOGIN ERROR\n Please check Your Username and Password\n";
        Menu();
    }
}

void Registration(){
	int currentLineNum=1;
	string ruserID, rpassword, rid, rpass;
	system("cls");
	cout<<"\t\t\t Enter the Username : ";
	cin>>ruserID;
	cout<<"\t\t\t Enter the password : ";
	cin>>rpassword;
	string str= ruserID + " " + rpassword;
	str = crypt('e',str);
	h.Insert(str);
	system("cls");
	cout<<"\n\t\t\t Registration Successfull !\n";
	Menu();
}

string crypt(char choice, string a){	
	int i; 
	switch(choice){
		case 'e':			
	    	for(i = 0;i < a.length(); i++){
		        a[i] = a[i] + 8; 
			}
	        break;
	
	   	case 'd':   		
	        for(i = 0; i < a.length(); i++){
	        	a[i] = a[i] - 8; 
			}
	        break;
	    default:
	        cout<<"Error";
	    }	
		return a;	
}

int main() {
    
    Menu();
    return 0;
}







