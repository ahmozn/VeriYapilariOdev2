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
        levels->addLeaf(level,newNode);
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

void BST::treeprint(){
    int i=0;
    //Queue* q=lot(root);
    //QueueNode* qtmp=q->getFirst();
    //BSTNode* temp=q->frontNodeValue();
    BSTNode* temp=getRoot();
    while(i<height(getRoot())){
        int val=printlv(i);
        if(i==0){
            if(temp->left!=nullptr&&temp->right!=nullptr){
                cout<<setw(1+val/2)<<"";
                for(int i=0;i<=val;i++) cout<<"x";
            }
            else if(temp->left!=nullptr){
                cout<<setw(1+val/2)<<"";
                for(int i=0;i<=val/2;i++) cout<<"x";
                //temp=temp->left;
            }
            else if(temp->right!=nullptr){
                cout<<setw(1+val)<<"";
                for(int i=0;i<=val/2;i++) cout<<"x";
                //temp=temp->right;
            }
        }
        else if(i>0){
            if(i==1){
                cout<<setw(1+val/2)<<"";
                for(int y=0;y<2;y++){
                    for(int i=0;i<=val;i++) cout<<".";
                    cout<<setw(val-1)<<"";
                }
            }else{
                cout<<setw(1+val/2)<<"";
                for(int y=0;y<pow(2,i);y++){
                    for(int i=0;i<=val;i++) cout<<".";
                    cout<<setw(val-1)<<"";
                }
            }
        }
        // qtmp=qtmp->next;
        // if(qtmp!=nullptr)temp=qtmp->treeNode;
        i++;
        cout<<endl;
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

    int val=pow(2,height(root)-1);
    while(levelNode){
        InnerNode* head=levelNode->innerListHead;
        InnerNode* currInner=head;
        InnerNode* prevInner=currInner;
        cout<<setw(val)<<"";
        prevInner=prevLevel->innerListHead;
        int sayac=0;
        //while(prevInner){
            while(currInner&&prevInner){
            //cout<<setw(1+val*2-3)<<"";
                if(prevInner->node->left!=nullptr && prevInner->node->right!=nullptr){
                    cout<<currInner->node->data;
                    cout<<setw(1+ val*2-3)<<"";
                    sayac++;
                }
                else if(prevInner->node->left!=nullptr && prevInner->node->right==nullptr){
                    cout<<currInner->node->data;
                    cout<<setw(1+ val*2-3)<<"";
                    cout<<setw(2+ val*2-3)<<"";
                    prevInner=prevInner->next;
                }
                else if(prevInner->node->left==nullptr && prevInner->node->right!=nullptr){
                    if(levelNode->level!=0) {
                        cout<<setw(1+val*2)<<"";
                        val=val*3;
                    }
                    cout<<currInner->node->data;
                    cout<<setw(1+ val*2-3)<<"";
                    prevInner=prevInner->next;
                }
                //prevInner=currInner;

                currInner=currInner->next;
                if(sayac==2) {
                    prevInner=prevInner->next;
                    sayac=0;
                }
            }
        //}
        
        cout<<endl;
        currInner=head;
        while(currInner){
            if(currInner->node->left!=nullptr && currInner->node->right!=nullptr){
                cout<<setw(val)<<"";
                cout<<"|";
                cout<<setw(val)<<"";
            }
            else if(currInner->node->left!=nullptr && currInner->node->right==nullptr){
                cout<<setw(val)<<"";
                cout<<"|";
                cout<<setw(val-1)<<"";
            }
            else if(currInner->node->left==nullptr && currInner->node->right!=nullptr){
                cout<<setw(val)<<"";
                cout<<"|";
                cout<<setw(val)<<"";
            }
            currInner=currInner->next;
        }
        cout<<endl;

        currInner=head;
        while(currInner){
            if(currInner->node->left!=nullptr && currInner->node->right!=nullptr){
                cout<<setw(val/2)<<"";
                for(int i=0;i<val;i++) cout<<".";
                cout<<setw(val/2)<<"";
            }
            else if(currInner->node->left!=nullptr && currInner->node->right==nullptr){
                cout<<setw(val/2)<<"";
                for(int i=0;i<val/2;i++) cout<<"<";
                cout<<setw(val-1)<<"";
            }
            else if(currInner->node->left==nullptr && currInner->node->right!=nullptr){
                cout<<setw(val)<<"";
                for(int i=0;i<val/2;i++) cout<<">";
                cout<<setw(val)<<"";
            }
            currInner=currInner->next;
        }
        cout<<endl;

        val=val/2;
        prevLevel=levelNode;
        levelNode=levelNode->next;
    }
    // //son satır yazdırılıyoer
    // cout<<setw(val*2)<<"";
    // InnerNode* crr=prevLevel->innerListHead;
    // while(crr){
    //         cout<<crr->node->data;
    //         cout<<setw(1+val*4-3)<<"";
    //         crr=crr->next;
    // }
    cout<<endl;
}

int BST::printlv(int n){
    BSTNode* temp=getRoot();
    int val= pow(2,height(root)- n+2);
    cout<<setw(val)<<"";
    displv(temp,n,val);
    cout<<endl;
    //cout<<setw(1+val/2)<<"";
    //for(int i=0;i<val/2+1;i++) cout<<".";
    return val;
}

//TEK IHTIYAC COCUK VARSA NOKTA YAZDIR YOKSA YAZDIRMA ŞEKLİNDE 
//bir de sağ taraf için çağrılması var tabi
void BST::displv(BSTNode* p, int lv, int d){
    int disp = 2 * d;
    if (lv == 0){
        if (p == NULL){

            cout << " x ";
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
    int val=pow(2,height(root)+2);
    while (!q->empty() && h<height(root)) {
        int levelSize = q->size();  // Mevcut seviyedeki düğüm sayısı
        cout << endl;

        cout<<setw(val)<<"";
        for (int i = 0; i < levelSize; ++i) {
            BSTNode* curr = q->frontNodeValue();
            q->dequeue();   


            // Çocukları kuyruğa ekleme
            if (curr) {
                cout << " " << curr->data << " " << setw(1+ 2 * val - 3);

                q->enqueue(curr->left);
                q->enqueue(curr->right);
            } else {
                cout << " x " << setw(1+ 2*val-3) << "";
            }
        }

        cout << endl; // Seviyeyi bitirdikten sonra yeni satıra geç

        // 2. Adım: Çocuk bağlantıları için noktaları koy
        for (int i = 0; i < levelSize; ++i) {
            BSTNode* curr = q->frontNodeValue();
            if(curr){
                if (curr->left!=nullptr && curr->right!=nullptr){
                    cout<<setw(1+val/2)<<"";
                    for(int i=0;i<=val;i++) cout<<"b";
                }
                if(curr->left!=nullptr && curr->right==nullptr){
                    cout<<setw(1+val/2)<<"";
                    for(int i=0;i<=val/2;i++) cout<<"a";
                }
                if(curr->left==nullptr && curr->right!=nullptr){
                    cout<<setw(1+val)<<"";
                    for(int i=0;i<=val/2;i++) cout<<"o";
                }
            }
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

//constructor
BST::BST():root(nullptr), levels(new OuterList()){}
//destructor
BST::~BST(){
    //agacSil(root);
}