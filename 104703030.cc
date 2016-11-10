#include<iostream>
using namespace std;

class bottles {
	public:
		bottles() {
			empty = 0;
			full = 0;
			count = 0;
		};
		void set(int full, int empty) {
			this->empty = empty;
			this->full = full;
			count = 0;
		};
		int getfull(){
			return full;
		}	
		int getempty(){
			return empty;
		}
		int getcount(){
			return count;
		}
		void oneroundchange() {
			count += full;
			empty += full;
			full = 0;
			while(empty > 2 && empty >= 0) {
				full++;	
				empty -= 3;
			}
		}	
		
	private:
		int empty;
		int full;
		int count;
};


int main() {
	int total = 0;
	while(cin >> total) {
		int max = 0;
		for(int i = 0; i <= 10; i++) {
			bottles stituation;
			stituation.set(total, i);
			while(1) {
				if(stituation.getfull() == 0){
					if(stituation.getempty() < 3) {
						break;
					}	
				}
				stituation.oneroundchange();
			}
			if(stituation.getempty() != i) {
				continue;
			}
			if(max < stituation.getcount()) {
				max = stituation.getcount();
			}
		}
		cout << max << endl;
	}
}

