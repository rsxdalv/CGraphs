#include <iostream>
#include "cilveks.h"
using namespace std;

Cilveks::Cilveks(string vu, unsigned int v, float mbc, int id)
{
   ID=id;
   setName(vu);
   setAge(v);
   setMBCena(mbc);
   std::cout << "Cilveka konstruktors [ID:"<<id<<"]"<<std::endl;
}   
Cilveks::~Cilveks()
{
   std::cout << "Cilveka destruktors [ID:"<<ID<<"]"<< std::endl;
}
void Cilveks::setName(string v)
{
   VdsUzv=v;
}
string Cilveks::getName() const
{
   return VdsUzv;
}
void Cilveks::setAge(unsigned int v)
{
   Vecums=v;
}
unsigned int Cilveks::getAge() const
{
   return Vecums;
}
void Cilveks::setMBCena(float mbc)
{
   if(mbc>0) MBCena=mbc;
   else MBCena=0;
}
float Cilveks::getMBCena() const
{
   return MBCena;
}
