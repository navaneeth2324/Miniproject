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
/**
 * @brief Enum to get the status of a function
 * 
 */
typedef enum status{
    SUCCESS=1,
    FAIL=0,
}status;
/**
 * @brief Function to Display the main menu of the contact application
 * 
 */
void menu();

/**
 * @brief 
 * 
 */
void got();

/**
 * @brief Function to Add a contact
 * 
 */
void create_contact();
/**
 * @brief Function to display all the contacts stored
 * 
 */
void list_contacts();
/**
 * @brief Function to Modify or edit the Contacts stored
 * 
 */
void edit_contact();
/**
 * @brief Function to Remove the contact stored
 * 
 */
void delete_contact();
/**
 * @brief Function to Search for a contact 
 * 
 */
void search_contacts();


#endif