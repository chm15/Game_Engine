#=============== Copyright Connor McLaughlan, All rights reserved. =============
#
#    Description: Recursively finds all "Notes.txt" files in directory tree.
#       Formats each text document then combines into "Documentation.txt".
#
#===============================================================================

import os
from glob import glob



def recursiveSearch(filename):
    '''
    Recursively searches all subdirectories.
    :param filename string
    :return [string] paths
    '''
    BASE_DIR = os.getcwd()
    paths = [y for x in os.walk(BASE_DIR) for y in glob(os.path.join(x[0], filename))]
    return paths


def getDirectoryName(path):
    '''
    Will the name of the directory of a file.
    :param path string
    :return string name
    '''
    indices = [i for i in range(len(path)) if path[i] == '/']
    i1 = indices[-2] + 1  # Get rid of leading '/' by increasing index by one.
    i2 = indices[-1]
    dirName = path[i1:i2]
    return dirName


def main():
    paths = recursiveSearch("Notes.txt")
    outFile = open("Documentation.txt", 'w')

    # Write documentation header.
    outFile.write("\tGame Engine Documentation\n\tby Connor H. McLaughlan\n\n\n")

    # Format and append each partial document into the full document
    for path in paths:
        dirName = getDirectoryName(path)
        inFile = open(path, 'r')

        # Write sub-header
        outFile.write("\n\n" + "===== " + dirName + " =====")

        for line in inFile:
            # Don't write line to outFile if it is the copyright header.
            if "Copyright Connor McLaughlan, All rights reserved." in line:
                pass
            else:
                outFile.write(line)
        inFile.close()

    # Write documentation footer.
    outFile.write("\n\n\n=============== Copyright Connor McLaughlan, All rights reserved. =============")
    outFile.close()


main()
