#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../include/audiostream.h"

void test_start_and_stop_audiostream(void)
{
    printf("Starting test_start_and_stop_audiostream...\n");

    PaStream *stream = NULL;
    int err;

    // Test starting and stopping the audio stream
    err = start_audiostream(&stream);
    assert(err == paNoError);
    if (stream != NULL)
    {
        err = stop_audiostream(&stream);
        assert(err == paNoError);
    }

    printf("test_start_and_stop_audiostream passed.\n");
}

void test_error_handling()
{
    printf("Starting test_error_handling...\n");

    PaStream *stream = NULL;
    int err;

    // Test starting and stopping the stream twice
    err = start_audiostream(&stream);
    assert(err == paNoError);
    err = stop_audiostream(&stream);
    assert(err == paNoError);
    err = start_audiostream(&stream);
    assert(err == paNoError);
    err = stop_audiostream(&stream);
    assert(err == paNoError);

    // Test stopping the stream twice
    if (stream != NULL)
    {
        err = stop_audiostream(&stream);
        assert(err == paNoError);
        err = stop_audiostream(&stream);
        assert(err != paNoError); // This should fail
    }

    printf("test_error_handling passed.\n");
}

void test_null_stream()
{
    printf("Starting test_null_stream...\n");

    int err;

    // Test starting and stopping a NULL stream
    err = start_audiostream(NULL);
    assert(err != paNoError); // This should fail
    err = stop_audiostream(NULL);
    assert(err != paNoError); // This should fail

    printf("test_null_stream passed.\n");
}

int main()
{
    test_start_and_stop_audiostream();
    test_error_handling();
    test_null_stream();

    printf("All tests passed.\n");

    return 0;
}
