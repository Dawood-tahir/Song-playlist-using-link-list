#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct song{
	int id;
	string title;
	string name;
	int duration;
	song *p,*n;
};

class palylist{
	song *start,*cur,*temp; int count;
	public:
	palylist(){
			start = NULL;
			count = 0;
		}
		bool isDuplicate(int i){
			cur = start;
			while(cur!=NULL){
			     if(cur->id == i){
			     	return true;
				 } cur=cur->n;	
			} return false;
		}
		void insert(int i,string n,string t,int d){
			if (isDuplicate(i)){
				cout<<"\nInsertion failed ID must be Unique!!\n";
				return;
			}
			if (start == NULL){
				start = new song;
				start->id=i;
				start->name=n;
				start->title=t;
				start->duration=d;
				start->n=NULL;
				start->p=NULL;
				count++;
			}
			else{
				cur = start;
				
				while(cur->n!=NULL)
				   cur = cur->n;
				
				temp = new song;
				temp->id=i;
				temp->name=n;
				temp->title=t;
				temp->duration=d;
				temp->n=NULL;
				temp->p=cur;
				cur->n=temp;
				count++;
			}
		}
		
		void search(){
			int c; bool found=false; string n, t;
			cur = start;
			cout<<"Search by Artist name(1) or Title(2) ";
			cin>>c;
			
			if (c == 1){
				cout<<"Enter Name of The Singer: ";
				cin>>n;
				while(cur!=NULL){
					if (cur->name==n){
						cout<<"Found!!\n";
						cout<<cur->id<<" "<<cur->name;
						found = true; cout<<endl;
					} cur = cur->n;
					
				} if (!found){
					cout<<"Invalid!!\n"; cout<<endl;
				}
			} 
			else if (c == 2){
				cout<<"Enter Title of The song: ";
				cin>>t;
				while(cur!=NULL){
					if (cur->title==t){
						cout<<"Found!!\n\n";
						cout<<cur->name<<" "<<cur->id;
						found = true; cout<<endl;
					} cur = cur->n;
					
				} if (!found){
					cout<<"Invalid!!\n\n";
				}
			}
			else {
				cout<<"Invliad!!\n\n";
			}
			
		}
		
		void update(){
			int n;
			cur = start;
			
				cout<<"Enter Id of The Song: ";
				cin>>n;
				while(cur!=NULL){
					if (cur->id==n){
						cout<<"Found!!\n";
						
                        cin.ignore();
                        cout << "Enter New Artist Name: ";
                        getline(cin, cur->name);

                        cout << "Enter New Song Title: ";
                        getline(cin, cur->title);

                        cout << "Enter New Duration (secs): ";
                        cin >> cur->duration;
                        cout<<"Updation SuccessFull!!\n";
                        return;
					} cur = cur->n;
				}  cout<<"No Record Found\n";
			}
			
			void dispaly(){
				
				cur = start;
			    while(cur != NULL){
			    
					cout<<"ID: "<<cur->id<<"\t\tSong Title: "<<cur->title<<"\t\tArtist Name: "<<cur->name<<"\t\tDuration(sec) "<<cur->duration;
					cout<<endl;
					cur = cur->n;
					
					} cout<<"Total Songs in playlist: "<<count; cout<<endl;
			}
			
			void playnext(int i){
				
				cur = start;
				while (cur != NULL){
					
					if (cur->id == i){
					   if (cur->n!=NULL){
					    cur=cur->n;
						cout<<"Now Playing "<<cur->title<<" Song!!\n";
			        }   
					else{
						cout<<"This is the last song!!\n";
					} return;  
					
					} cur=cur->n;
					
				}  
				cout<<"Song not Found!!\n";
				
			}
			
			void playpervious(int i){
				
				cur = start;
				while (cur != NULL){
					if (cur->id == i){
					   if ( cur->p!= NULL){
					    cur=cur->p;
						cout<<"Now Playing "<<cur->title<<" Song!!\n";
			        }   
					else{
						cout<<"This is the First song!!\n";
					} return;  
					} cur=cur->n;
				}  
				cout<<"Song not Found!!\n";
				
			}
			
		
};
int main(int argc, char** argv) {
	palylist l;
	int c;
	do{ 
	cout<<"======WELCOME TO OUR MUSIC APP=======\n";
	    cout<<"1. To insert\n2. To Search\n3. To update\n4. To Display\n5. Play Next\n6. Play pervious\n";
		cout<<"Enter your choice: ";
		cin>>c;
		cout<<endl;
		switch(c){
			case 1: {
			int i,d; string a, t;

            cout << "Enter ID: ";
            cin >> i;
            cin.ignore();

            cout << "Enter Artist Name: ";
            getline(cin, a);

            cout << "Enter Song Title: ";
            getline(cin, t);

            cout << "Enter Duration (secs): ";
            cin >> d;

            l.insert(i, a, t, d); cout<<endl;
           break; }
			case 2:
				l.search(); cout<<endl; break;
			case 3:
				l.update(); cout<<endl; break;
			case 4: 
			    l.dispaly(); cout<<endl; break;
			case 5:
				int id;
			     cout<<"Enter ID of cur song: ";
				 cin>>id;
				 l.playnext(id); cout<<endl; break;
			case 6: 
			    cout<<"Enter ID of cur song: ";
				 cin>>id;
				 l.playpervious(id); cout<<endl; break;	
			case 7:
			     cout<<"Existing!!\n"; break;
			default:
			    cout<<"Invalid Try Again!!\n"; cout<<endl; break;			
		}
	} while(c != 7);
	return 0;
}
