  printf("\nFollowers:\n");

                if (currentUser->followerCount == 0) {
                    printf("No followers.\n");
                }
                else {
                    for (int i = 0;
                         i < currentUser->followerCount;
                         i++) {

                        printf("%s\n",
                               currentUser->followers[i]->username);
                    }
                }
            }
                    printf("%s was removed from your followers.\n", username);
                else
                    printf("%s is not your follower.\n", username);
            }

            else if (choice == 6) {

                printf("Logged out.\n");
                currentUser = NULL;
            }
        }
    }

    return 0;
}