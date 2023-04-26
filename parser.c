#include "shell.h"

/**
 * is_executable - determines if a file is an executable
 * @path: path to the file
 *
 * Return: true if the file is an executable, false otherwise
 */
bool is_executable(const char *path)
{
    struct stat st;
    if (stat(path, &st) == -1)
    {
        return false;
    }
    return (bool)(st.st_mode & S_IXUSR);
}

/**
 * extract_substring - extracts substring between start and end positions
 * @start: starting position of the substring
 * @end: ending position of the substring
 * @str: string to extract substring from
 *
 * Return: pointer to new buffer containing the extracted substring
 */
char *extract_substring(int start, int end, const char *str)
{
    static char buf[1024];
    int buf_pos = 0;
    for (int i = start; i < end && str[i]; i++)
    {
        if (str[i] != ':')
        {
            buf[buf_pos++] = str[i];
        }
    }
    buf[buf_pos] = '\0';
    return buf;
}

/**
 * find_executable_path - finds the full path of an executable in PATH
 * @env: pointer to environment variables
 * @cmd: command to find
 *
 * Return: pointer to buffer containing full path of executable, or NULL if not found
 */
char *find_executable_path(char **env, const char *cmd)
{
    const char *path_env = getenv("PATH");
    if (!path_env)
    {
        return NULL;
    }
    if (strstr(cmd, "./") == cmd && is_executable(cmd))
    {
        return strdup(cmd);
    }
    size_t cmd_len = strlen(cmd);
    size_t path_env_len = strlen(path_env);
    char *path = (char *)path_env;
    char *full_path = NULL;
    for (size_t i = 0; i <= path_env_len; i++)
    {
        if (path[i] == ':' || path[i] == '\0')
        {
            full_path = extract_substring(path - path_env, i - path_env, path_env);
            strcat(full_path, "/");
            strcat(full_path, cmd);
            if (is_executable(full_path))
            {
                return full_path;
            }
            free(full_path);
        }
    }
    return NULL;
}
