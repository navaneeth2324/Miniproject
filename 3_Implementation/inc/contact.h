/**
 * @file contact.h
 * @author Navaneeth M (navneeth023@gmail.com.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>


#ifndef __CONTACT_H__
#define __CONTACT_H__
/**
 * @brief Structure Variable to store the Contact Details of a person
 * 
 */
struct person
{
    char name[35];
    char address[50]; 
    long int mble_no;
    char mail[100];
    
};

void menu();
void got();
void create_contact();
void list_contacts();
void edit_contact();
void delete_contact();
void search_contacts();


#endif