//
// Created by Conor Sievwright on 09/05/2022.
//

#ifndef INC_0905_TWITTER_CREATE_H
#define INC_0905_TWITTER_CREATE_H
#endif //INC_0905_TWITTER_CREATE_H
#define TWEET_LENGTH 280
#define USR_LENGTH 100
#define MAX_TWEETS 100
#define MAX_FOLLOWERS 30
#define MAX_FOLLOWING 30
#define MAX_USERS 100
typedef struct tweet{
int id;
char msg[TWEET_LENGTH];
char user[USR_LENGTH];

}tweet;

typedef struct user{
   char username[USR_LENGTH];
   char followers[MAX_FOLLOWERS];
   int num_followers;

   char following[MAX_FOLLOWING];
   int num_following;

}user;

typedef struct twitter{
    tweet news_feed[MAX_TWEETS];
    user users[MAX_USERS];
    int num_tweets;
    int num_users;
    int counter;
}twitter;

void create_twitter_system(twitter* twitter_system);
void endTurn(twitter* twitter_system);
void follow(twitter* twitter_system);
void unfollow(twitter* twitter_system);