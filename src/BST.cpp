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
//--------------------------PRIVATE--------------------------

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

//güncellenecek
void BST::agacCiz(BSTNode* root, int level, int space){
    if(root==nullptr) return;
    // if(root->left!=nullptr && root->right!=nullptr){
    //     std::cout<<std::endl;
    //     for(int i=0;i<level*3;i++) std::cout<<".";
    //     std::cout<<root->data<<std::endl;
    //     agacCiz(root->left,level-1);
    //     agacCiz(root->right,level-1);
    // }

    for(int i=0;i<level*3;i++) std::cout<<".";
    std::cout<<root->data<<std::endl;

    agacCiz(root->right, level-1, space+5);

    // if(level>0) for(int i=0;i<space;i++) std::cout<<' ';
    // std::cout<<root->data<<std::endl;

    agacCiz(root->left, level-1, space+5);
}
//--------------------------PUBLIC--------------------------

//public düğüm ekleme
BSTNode* BST::ekle(char chr){
    root=dugumEkle(root,chr,0);
    return root;
}

//public aynalama
void BST::aynala(){
    ayna(root);
}

//güncellenecek
void BST::ciz(int level, int space){
    agacCiz(root,height(root),space);
}

//ağacın değerini döndüren rekürsif fonksiyon
int BST::toplam(BSTNode* root, bool isLeft){
    if(root==nullptr){
        return 0;
    }

    int leftSum=toplam(root->left,true);
    int rightSum=toplam(root->right,false);

    int deger;
    //sol düğümse 2 ile çarparak al
    if(isLeft){
        deger=root->data*2;
    }
    //sağ düğümse olduğu gibi al
    else{
        deger=root->data;
    }

    return leftSum+deger+rightSum; //yaprağın değerini toplam değere ekle
}

//ağacın kök düğümünü döndürür
BSTNode* BST::getRoot() const{
    return root;
}

//atıl
void BST::tyaz(BSTNode* node) const{
    if (node != nullptr) {
        tyaz(node->left);
        std::cout << node->data << " ";
        tyaz(node->right);
    }
}
//atıl
void BST::yazdir() const{
    tyaz(root);
    std::cout<<std::endl;
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

//ağaç çizme işlemini gerçekleştirir
void BST::treeprint(){
    int i=0;
    doldurAll(getRoot(),' ');

    while(i<height(getRoot())){
        int val=printlv(i); //seviyeyi yazdırma
        //düğümün altındaki çizgiler
        if(i<height(getRoot())-1){
            if(root->left!=nullptr && root->right!=nullptr){
                for(int y=0; y<pow(2,i); y++){
                    cout<<setw(2+val)<<"|";
                    cout<<setw(val-2)<<"";
                }
            }else if(root->right==nullptr){
                for(int y=0; y<pow(2,i)/2; y++){
                    cout<<setw(2+val)<<"|";
                    cout<<setw(val-2)<<"";
                }
            }else if(root->left==nullptr){
                if(i!=0){
                    for(int y=0; y<pow(2,i)/2; y++){
                        cout<<setw(2+val)<<" ";
                        cout<<setw(val-2)<<"";
                    }
                }
                for(int y=0; y<pow(2,i)/2; y++){
                    cout<<setw(2+val)<<"|";
                    cout<<setw(val-2)<<"";
                }
            }else{
                cout<<setw(2+val)<<" ";
                cout<<setw(val-2)<<"";
            }
        }
        cout<<endl;

        //bağlantılar
        if(i==0){
            if(root->left!=nullptr && root->right!=nullptr){ //kök düğümün iki çocuğu da varsa
                cout<<setw(1+val/2)<<"";
                for(int i=0;i<=val;i++) cout<<".";
            }
            else if(root->right==nullptr){ //kök düğümün sağ çocuğu yoksa
                cout<<setw(1+val/2)<<"";
                for(int i=0;i<=val/2;i++) cout<<"<";
            }
            else if(root->left==nullptr){ //kök düğümün sol çocuğu yoksa
                cout<<setw(1+val)<<"";
                for(int i=0;i<=val/2;i++) cout<<">";
            }
        }
        else if(i>0 && i<height(getRoot())-1){
            if(root->left!=nullptr && root->right!=nullptr){ //kök düğümün iki çocuğu da varsa
                cout<<setw(1+val/2)<<"";
                for(int y=0;y<pow(2,i);y++){
                    for(int i=0;i<=val;i++) cout<<".";
                    cout<<setw(val-1)<<"";
                }
            }else if(root->right==nullptr){ //kök düğümün sağ çocuğu yoksa
                cout<<setw(1+val/2)<<"";
                for(int y=0;y<pow(2,i)/2;y++){
                    for(int i=0;i<=val;i++) cout<<".";
                    cout<<setw(val-1)<<"";
                }
            }else if(root->left==nullptr){ //kök düğümün sol çocuğu yoksa, sadece sağ taraf için bağlantı çizilir
                if(i!=0){ //ilk seviye harici sol tarafı "boşluk" olarak değerlendir
                    cout<<setw(1+val/2)<<"";
                    for(int y=0;y<pow(2,i)/2;y++){
                        cout<<setw(val*2)<<"";
                    }
                }
                for(int y=0;y<pow(2,i)/2;y++){ //kök düğümün sağ tarafı için noktalar yazdırılır
                    for(int i=0;i<=val;i++) cout<<".";
                    cout<<setw(val-1)<<"";
                }
            }
        }
        i++;
        cout<<endl;
    }
}

void BST::doldur(BSTNode* root, char chr){
    if (root == nullptr) return; // Ağaç boşsa işlemi durdur

    // Eğer sol düğüm boşsa yeni bir düğüm oluştur ve sabit değeri ata
    if (root->left == nullptr) {
        root->left = new BSTNode(' ');
    } else {
        doldur(root->left, ' '); // Sol alt ağacı kontrol et
    }

    // Eğer sağ düğüm boşsa yeni bir düğüm oluştur ve sabit değeri ata
    if (root->right == nullptr) {
        root->right = new BSTNode(' ');
    } else {
        doldur(root->right, ' '); // Sağ alt ağacı kontrol et
    }
}

void BST::doldurLevel(BSTNode* root, int level, char chr){
    if (root == nullptr) return;

    if (level == 1) {
        // Sol ve sağ düğümleri kontrol et ve eksikse doldur
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

void BST::doldurAll(BSTNode* root, char chr) {
    int h = height(root);
    for (int i = 1; i < h; ++i) {
        doldurLevel(root, i, ' ');
    }
}

void BST::yaz(){
    BSTNode* root=getRoot();

    OuterList* levels=getLevelsList();
    OuterNode* levelNode= levels->head;
    OuterNode* prevLevel=levelNode;

    cout<<endl;
    levels->print();
    cout<<endl;

    int val=pow(2,height(root)+1);
    while(levelNode){
        InnerNode* head=levelNode->innerListHead;
        InnerNode* currInner=head;
        InnerNode* prevInner=currInner;
        cout<<setw(val)<<"";
        prevInner=prevLevel->innerListHead;
        int sayac=0;

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
        cout<<setw(val)<<"";
        currInner=head;
        while(currInner && currInner->node->left && currInner->node->right){
            if(currInner->node->left->data==' ' && currInner->node->right->data==' '){
                cout<<"   ";
                cout<<setw(val*2-3)<<"";
            }else{
                cout<<" | ";
                cout<<setw(val*2 -3)<<"";
            }
            currInner=currInner->next;
        }

        cout<<endl;

        cout<<setw(val/2+1)<<"";
        currInner=head;
        while(currInner && currInner->node->left && currInner->node->right){
            if(currInner->node->left->data!=' ' && currInner->node->right->data!=' '){
                for(int i=0;i<=val;i++) cout<<".";
                //cout<<setw(val/2+1)<<"";
            }
            else if(currInner->node->left->data!=' ' && currInner->node->right->data==' '){
                for(int i=0;i<=val/2;i++) cout<<"<";
                cout<<setw(val/2)<<"";
            }
            else if(currInner->node->left->data==' ' && currInner->node->right->data!=' '){
                cout<<setw(val/2)<<"";
                for(int i=0;i<=val/2;i++) cout<<">";
            }else{
                cout<<setw(val+1)<<"";
            }
            cout<<setw(val-1)<<"";
            currInner=currInner->next;
        }
        cout<<endl;
        //cout<<val<<endl;
        val=val/2;
        prevLevel=levelNode;
        levelNode=levelNode->next;
    }
    cout<<endl;
}

int BST::printlv(int n){
    BSTNode* temp=getRoot();
    int val= pow(2,height(root)- n);
    cout<<setw(val)<<"";
    displv(temp,n,val);
    cout<<endl;
    return val;
}

//TEK IHTIYAC COCUK VARSA NOKTA YAZDIR YOKSA YAZDIRMA ŞEKLİNDE 
//bir de sağ taraf için çağrılması var tabi
void BST::displv(BSTNode* p, int lv, int d){
    int disp = 2 * d;
    if (lv == 0){
        if (p == NULL){
            cout << " X ";
            cout << setw(disp -3) << "";
            return;
        }
        else{
            //int result = ((p->data <= 1) ? 1 : log10(p->data) + 1);
            cout << " " << p->data << " ";
            cout << setw(disp -3) << "";
        }
    }
    else
    {
        if (p == NULL&& lv >= 1){
            displv(NULL, lv - 1, d);
            displv(NULL, lv - 1, d);
        }
        else{
            displv(p->left, lv - 1, d);
            displv(p->right, lv - 1, d);
        }
    }
}

//meh
Queue* BST::lot(BSTNode* root){
    if (root == nullptr) return nullptr;


    Queue* q = new Queue();
    q->enqueue(root);
    
    int h=0;
    int val=pow(2,height(root));
    while (!q->empty() && h<height(root)) {
        int levelSize = q->size();  // Mevcut seviyedeki düğüm sayısı
        cout << endl;

        cout<<setw(val)<<"";
        for (int i = 0; i < levelSize; ++i) {
            BSTNode* curr = q->frontNodeValue();
            q->dequeue();   
            // Çocukları kuyruğa ekleme
            if (curr) {
                cout << " " << curr->data << " " << setw(2 * val - 3);

                q->enqueue(curr->left);
                q->enqueue(curr->right);
            } else {
                cout << " x " << setw(2*val-3) << "";
            }
        }

        cout << endl; // Seviyeyi bitirdikten sonra yeni satıra geç

        // 2. Adım: Çocuk bağlantıları için noktaları koy
        for (int i = 0; i < levelSize; ++i) {
            BSTNode* curr = q->frontNodeValue();
            q->dequeue();
            if(curr){
                if (curr->left!=nullptr && curr->right!=nullptr){
                    cout<<setw(1+val/2)<<"";
                    for(int i=0;i<=val;i++) cout<<".";
                }
                else if(curr->left!=nullptr && curr->right->data==' '){
                    cout<<setw(1+val/2)<<"";
                    for(int i=0;i<=val/2;i++) cout<<"a";
                }
                else if(curr->right!=nullptr && curr->left->data==' '){
                    cout<<setw(1+val)<<"";
                    for(int i=0;i<=val/2;i++) cout<<"o";
                }
                q->enqueue(curr->left);
                q->enqueue(curr->right);
            }
            cout<<endl;
        }

        cout << endl;
        val = val / 2;
        h++;
    }
    
    return q;
}

OuterList* BST::getLevelsList(){
    return levels;
}

void BST::updateLevels(BSTNode* root, OuterList* outerlist, int level){
    if (root == nullptr) return;

    levels->addLeaf(level, root);

    // Alt düğümleri kontrol et
    updateLevels(root->left, levels, level + 1);
    updateLevels(root->right, levels, level + 1);
}

//constructor
BST::BST():root(nullptr), levels(new OuterList()){}
//destructor
BST::~BST(){
    //agacSil(root);
}