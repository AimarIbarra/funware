import os
import random
import sys
import copy

should_chdir_to_home = True

def print_help():
    print("This is program will shuffle your filenames recursively, so be careful!")
    exit(0)
    
def handle_args():
    s = len(sys.argv)
    if s > 2:
        print("Too many arguments.");
        exit(1)
    if s > 1:
        if sys.argv[1] == "help":
            print_help()
        else:
            print("Invalid argument: ", argv[1])
            exit(1)

def rename_files(oldnames, newnames):
    for (oldname, newname) in zip(oldnames, newnames):
        os.rename(oldname, newname)
        
def shuffle_current_dir():
    files = os.listdir(".")
    shuffled = files.copy()
    random.shuffle(shuffled)
    # The new names need a hash in order to avoid deletions
    hashed = map(lambda x: "tmp_hash_235874" + x, copy.deepcopy(shuffled))
    rename_files(files, hashed)
    rename_files(hashed, shuffled)

def shuffle_recursively():
    shuffle_current_dir()
    dirs = filter(os.path.isdir, os.listdir("."))
    for dir in dirs:
        os.chdir(dir)
        shuffle_recursively()
        os.chdir("..")
        
def main():
    handle_args()
    shuffle_recursively()

if __name__ == "__main__":
    main()
