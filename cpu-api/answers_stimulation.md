1.
    ```
                            Process Tree:
                                a

    Action: a forks b
                                a
                                └── b
    Action: a forks c
                                a
                                ├── b
                                └── c
    Action: c EXITS
                                a
                                └── b
    Action: a forks d
                                a
                                ├── b
                                └── d
    Action: a forks e
                                a
                                ├── b
                                ├── d
                                └── e
    ```

2. The final process trees will have more branches (child processes) as the fork percentage increases and vice versa. 

3. a forks b -> b forks c -> a forks d -> c forks e, e EXITS

4. When `c` is terminated, its children which are `d` and `e` are now children of `a` which is the initial process. With flag `-R`, `d` and `e` are now children of `b` which is the closest parent of `c` before it being terminated.

5. 
    ```
    Action: a forks b
    Action: b forks c
    Action: c EXITS
    Action: a forks d
    Action: a forks e
    a
    ├── b
    ├── d
    └── e
    ```

6. This is a tough question. One thing could be predicted is the same seed gives the same final process tree. The exact actions took place, otherwise, aren't always easy to determine, and idk why yet... :(
