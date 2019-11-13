#ifndef bst_h
#define bst_h
#include <initializer_list>
#include <iostream>
namespace struktury{	
	template <class T>
		class below{
			public:
				static bool por( T a, T b){ return a <= b; }
				static bool eq( T a, T b){ return a == b; }
		};

	template <class T>
		class above{
			public:
				static bool por( T a, T b){ return a >= b; }
				static bool eq( T a, T b){ return a == b; }
		};

	template <typename T, class C = below<T> >
		class bst{
			private:
				class node{
					private:
						T val;
						node* left;
						node* right;
						static void help_remove( node* root ){
							node* cur;
							node* pre;
							pre = root;
							cur = root->right;
							while( cur->left != nullptr ){
								pre = cur;
								cur = cur->left;
							}
							root->val = cur->val;
							if( pre != root ) pre->left = cur->right;
							else root->right = cur->right;
							delete cur;
						}

					public:
						node(T val) : val(val){ left = nullptr; right = nullptr; }

						static node* insert( node* root, T val ){
							if( root == nullptr ) root = new node(val);
							else if( C::por( val, root->val) ){
								if( root->left == nullptr ) root->left = new node( val );
								else root->left = insert( root->left, val );
							}
							else{
								if( root->right == nullptr ) root->right = new node( val );
								else root->right = insert( root->right, val );
							}
							return root;
						}

						static node* remove( node* root, T val ){
							node* pom;
							if( root != nullptr ){
								if( C::eq( val, root->val )){
									if( root->left == nullptr ){
										pom = root->right;
										delete root;
										root = pom;
									}
									else if( root->right == nullptr ){
										pom = root->left;
										delete root;
										root = pom;
									}
									else node::help_remove( root );
								}
								else if( C::por( val, root->val ) )
									root->left = remove( root->left, val );
								else root->right = remove( root->right, val );
							}
							return root;
						}

						static bool contains( node* root, T val){
							if( root != nullptr ){
								if( C::eq( val, root->val )) return true;
								else return contains( C::por( val, root->val) ? root->left : root->right, val );
							}
							return false;
						}

						friend std::ostream& operator <<( std::ostream& str, const node *root ){
							if( root != nullptr ) str << root->left << root->val << " "  << root->right;
							return str;
						}
				} *root;

			public:
				void remove( T val ){ root = node::remove( root, val ); }
				void insert( T val ){ root = node::insert( root, val ); }
				bool contains( T val ){ return node::contains( root, val ); }
				bst(){ root = nullptr; }
				bst( T val ){ root = new node( val ); }
				bst( std::initializer_list<T> ls ) : root(nullptr){
					auto wsk = ls.begin();
					for( unsigned int i = 0 ; i < ls.size() ; i++ )
						root = node::insert( root, wsk[i] );
				}

				friend std::ostream& operator <<( std::ostream& str, const bst &tree ){
					str << tree.root;
					return str;
				}
		};

}
#endif


