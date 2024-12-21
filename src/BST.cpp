/**
 * @file         BST.cpp
 * @description  BinarySearchTree yapısının bulunduğu kaynak dosyası. Programda kullanılacak olan
 *               bazı fonksiyonlar burada tanımlanmıştır.
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         11.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#include "BST.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
//------------------------------------------------------------------------------PRIVATE-----

//düğüm eklemek için rekürsif fonksiyon
BSTNode* BST::dugumEkle(BSTNode* node, char chr, int level){
    if (node == nullptr) {
        BSTNode* newNode=new BSTNode(chr);
        //levels->addLeaf(level,newNode);
        return newNode;  //hiç düğüm yoksa yeni düğüm oluştur
    }
    if (chr < node->data) {
        node->left = dugumEkle(node->left, chr, level+1);   //küçükse sol düğüm için çağır
    } else if (chr > node->data) {
        node->right = dugumEkle(node->right, chr, level+1); //büyükse sağ düğüm için çağır
    }
    return node;
}

//aynalama işlemi için rekürsif fonksiyon
void BST::ayna(BSTNode* root){
    if (root == nullptr) {
        return;
    }

    //sol ve sağ alt ağaçları yer değiştir
    BSTNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    //sol ve sağ alt ağaçları aynala
    ayna(root->left);
    ayna(root->right);
}

//destructor için rekürsif fonksiyon
void BST::agacSil(BSTNode* node){
    if(node==nullptr) return;

    agacSil(node->left);
    agacSil(node->right);

    delete node;
    node=nullptr;
}

//ağaç yazdırma için fonksiyon
void BST::agacCiz(){
    BSTNode* root=getRoot();

    OuterList* levels=getLevelsList();
    OuterNode* levelNode= levels->head;
    OuterNode* prevLevel=levelNode;

    int val=pow(2,height(root));
    while(levelNode){ //her seviye için yazdırma yapılır
        InnerNode* head=levelNode->innerListHead;
        InnerNode* currInner=head;
        cout<<setw(val)<<"";
        int sayac=0;

        //yaprak değerleri yazdırılır
        while(currInner){
            if(currInner->node->data!=' '){
                cout<<" "<<currInner->node->data<<" ";
                cout << setw(val*2 -3) << "";
            }else{
                cout<<"   ";
                cout << setw(val*2 -3) << "";
            }
            currInner=currInner->next;
        }
        
        cout<<endl;

        //yaprakların altındaki noktalar yazdırılır
        cout<<setw(val)<<"";
        currInner=head;
        while(currInner && currInner->node->left && currInner->node->right){
            if(currInner->node->left->data==' ' && currInner->node->right->data==' '){
                cout<<"   ";
                cout<<setw(val*2-3)<<"";
            }else{
                cout<<" . ";
                cout<<setw(val*2 -3)<<"";
            }
            currInner=currInner->next;
        }

        cout<<endl;

        //dallar yazdırılır
        cout<<setw(val/2+1)<<"";
        currInner=head;
        while(currInner && currInner->node->left && currInner->node->right){
            if(currInner->node->left->data!=' ' && currInner->node->right->data!=' '){
                for(int i=0;i<=val;i++) cout<<".";
            }
            else if(currInner->node->left->data!=' ' && currInner->node->right->data==' '){
                for(int i=0;i<=val/2;i++) cout<<".";
                cout<<setw(val/2)<<"";
            }
            else if(currInner->node->left->data==' ' && currInner->node->right->data!=' '){
                cout<<setw(val/2)<<"";
                for(int i=0;i<=val/2;i++) cout<<".";
            }else{
                cout<<setw(val+1)<<"";
            }
            cout<<setw(val-1)<<"";
            currInner=currInner->next;
        }
        cout<<endl;

        val=val/2;
        prevLevel=levelNode;
        levelNode=levelNode->next;
    }
    cout<<endl;
}

//ilgili seviyedeki boş düğümleri boş char ile doldurur
void BST::doldurLevel(BSTNode* root, int level, char chr){
    if (root == nullptr) return;

    if (level == 1) {
        //sol ve sağ düğümleri kontrol, eksikse doldur
        if (root->left == nullptr) {
            root->left = new BSTNode(' ');
        }
        if (root->right == nullptr) {
            root->right = new BSTNode(' ');
        }
    } else if (level > 1) {
        doldurLevel(root->left, level - 1, ' ');
        doldurLevel(root->right, level - 1, ' ');
    }
}

//her seviyenin düğümlerini ters çevirir. aynalama işleminden sonra kullanılır
void BST::updateLevels(){
    for(int i=0;i<height(getRoot());i++) levels->reverseInnerList(i);    
}
//-------------------------------------------------------------------------------PUBLIC-----

//public düğüm ekleme
BSTNode* BST::ekle(char chr){
    root=dugumEkle(root,chr,0);
    return root;
}

//public aynalama
void BST::aynala(){
    ayna(root);
    updateLevels(); //yazdırırken kullanacagımız listeyi de güncellemeliyiz
}

//ağaç yazdırma için fonksiyon
void BST::ciz(){
    agacCiz();
}

//ağacın değerini döndüren rekürsif fonksiyon
int BST::toplam(BSTNode* root, bool isLeft){
    if(root==nullptr){
        return 0;
    }

    int leftSum=toplam(root->left,true);
    int rightSum=toplam(root->right,false);

    int deger;
    if(root->data!=' '){//doldurma sonrası toplamda fark olmaması için doldurma değerleri atlıyoruz
        //sol düğümse 2 ile çarparak al
        if(isLeft){
            deger=root->data*2;
        }
        //sağ düğümse olduğu gibi al
        else{
            deger=root->data;
        }
    }else deger=0;

    return leftSum+deger+rightSum; //yaprağın değerini toplam değere ekle
}

//ağacın yüksekliğini döndürür
int BST::height(BSTNode* root){
    //ağaç boşsa
    if (root == nullptr) {
        return 0;
    }
    //sol ve sağ alt ağaçların yüksekliklerini hesapla
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    //hangisi büyükse onu alıp 1 ekle
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

//boş düğümler doldurulduktan sonra OuterList listesini günceller
void BST::updateLevels(BSTNode* root, OuterList* outerlist, int level){
    if (root == nullptr) return;

    levels->addLeaf(level, root);

    //alt düğümler için çağrılır
    updateLevels(root->left, levels, level + 1);
    updateLevels(root->right, levels, level + 1);
}

//ağaç yüksekliğince her level için doldurma işlemi yapılır
void BST::doldurAll(BSTNode* root, char chr) {
    int h = height(root);
    for (int i = 1; i < h; ++i) {
        doldurLevel(root, i, ' ');
    }
}

//ağacın kök düğümünü döndürür
BSTNode* BST::getRoot() const{
    return root;
}

//yazdırma için gereken OuterList listesini döndürür
OuterList* BST::getLevelsList(){
    return levels;
}



//constructor
BST::BST():root(nullptr), levels(new OuterList()){}
//destructor
BST::~BST(){
    //agacSil(root);
}