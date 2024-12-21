/**
 * @file         BST.hpp
 * @description  BinarySearchTree yapısının bulunduğu başlık dosyası.
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         11.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#ifndef BST_HPP
#define BST_HPP

#include "BSTNode.hpp"
#include "LevelList.hpp"

class BSTNode;

class BST{
    private: 
        BSTNode* root;    //kök düğüm      
        LevelList* levels; //seviyeler listesi

        BSTNode* dugumEkle(BSTNode* node, char chr, int level);    //düğüm eklemek için private fonksiyon
        void ayna(BSTNode* root);                       //aynalamak için private fonksiyon
        void agacSil(BSTNode* node);                    //silmek için private fonksiyon
        void agacCiz();                                 //ağaç çizmek için private fonksiyon

        void doldurLevel(BSTNode* root, int level, char chr);   //ilgili seviyedeki boş düğümleri doldurmak için fonksiyon
        void updateLevels();                            //ağaçtaki her seviyenin düğümlerini ters çeviren fonksiyon
    public:
        BSTNode* ekle(char chr);                        //düğüm ekle public
        void aynala();                                  //aynala public
        void ciz();                                     //ağaç çiz public
        int toplam(BSTNode* root, bool isLeft=false);   //ağaç değerini döndürür
        int height(BSTNode* root);                      //ağacın yüksekliğini döndürür


        void updateLevels(BSTNode* root, LevelList* LevelList, int level); //boş düğümler doldurulduktan sonra LevelList listesini günceller
        void doldurAll(BSTNode* root, char chr);        //ağaç yüksekliğince her level için doldurma işlemi yapılır

        BSTNode* getRoot() const;                       //ağaç kök düğümünü döndürür
        LevelList* getLevelsList();                     //ağacın LevelList'ini döndürür


        BST();   //constructor
        ~BST();  //destructor
};

#endif