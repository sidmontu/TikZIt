
/***********************************************************************************
 * MIT License
 *
 * Copyright (c) [2018] [Siddhartha]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "argparse.h"

static const char *const usage[] = {
    "tikzit [options] [[--] args]",
    "tikzit [options]",
    NULL,
};

void
parse_args(int argc, const char **argv, char **file, char **out)
{
    struct argparse_option options[] = {
        OPT_HELP(),
        OPT_GROUP("Basic options"),
        OPT_STRING('f', "file", file, "path to TikZ file"),
        OPT_STRING('o', "output", out, "output file path to TikZ figure"),
        OPT_END(),
    };

    struct argparse argparse;
    argparse_init(&argparse, options, usage, 0);
    argparse_describe(&argparse, "\nCreates a TikZ standalone figure.", "\nCreated by Siddhartha (2018).");
    argc = argparse_parse(&argparse, argc, argv);

    if (*file == NULL) {
        printf("You must provide an input file!\n\n");
        argparse_usage(&argparse);
        exit(1);
    }

    if (*out == NULL) {
        // Use same name as input file
        *out = strcat(*file,".pdf");
    }
}

int
main(int argc, const char **argv)
{
    char *file = NULL, *out = NULL;
    parse_args(argc,argv,&file,&out);

    return 0;
}
