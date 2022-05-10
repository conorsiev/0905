#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>
#include "twitter_create.h"

//
// Created by Conor Sievwright on 09/05/2022.
//
void create_twitter_system(twitter* twitter_system) {
    twitter_system->counter = 0;
    char str[100];
    printf("Type in how many users\n");
    fgets(str, 100, stdin);
    printf("\nNumber of Users: %s", str);
    twitter_system->num_users = atoi(str);

    for (int i = 0; i < twitter_system->num_users; i++) {
        printf("\ntype in name: ");
        fgets(twitter_system->users[i].username, USR_LENGTH, stdin);
        if (twitter_system->users[i].username[strlen(twitter_system->users[i].username) - 1] == '\n') {
            twitter_system->users[i].username[strlen(twitter_system->users[i].username) - 1] = '\0';
        }
        twitter_system->users[i].num_followers = 0;
        twitter_system->users[i].num_following = 0;
        printf("Name: %s, Followers: %d, Following: %d", twitter_system->users[i].username,
               twitter_system->users[i].num_followers, twitter_system->users[i].num_following);
    }


}
void endTurn(twitter* twitter1){

    twitter1->counter++;
  printf("\nIt is now: %s", twitter1->users[twitter1->counter].username);

}

void follow(twitter* twitter1){
    char followee[USR_LENGTH];
    user currentUser = twitter1->users[twitter1->counter];
    printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    printf("\nSelect from the list of users below to follow:");
    for(int i = 0; i<twitter1->num_users;i++) {
        if (strcmp(twitter1->users[i].username, currentUser.username) != 0) {
            printf("\n%d:  %s\n", i, twitter1->users[i].username);
        }

    }
    fgets(followee, USR_LENGTH, stdin);
    int intfollow = atoi(followee);
    strcpy(currentUser.following[currentUser.num_following], twitter1->users[intfollow].username);
    //currentUser.num_following++;
    twitter1->users[twitter1->counter].num_following++;

    user follower = twitter1->users[intfollow];
    strcpy(follower.followers[follower.num_followers], currentUser.username);
    twitter1->users[intfollow].num_followers++;


}

void unfollow(twitter* twitter_system){
    user currentUser = twitter_system->users[twitter_system->counter];
    printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    printf("\nUnfollow List:");
    printf("%d ",currentUser.num_following);
    for(int i = 0; i<currentUser.num_following;i++){
        if (strcmp(twitter_system->users[i].username, currentUser.username) != 0) {
            
        }
    }



}
