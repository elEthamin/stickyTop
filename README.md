# stickyTop

stickyTop is a C program that allows the user to set a window in "Always on Top" mode.

## Features

stickyTop offers the following features:

    * List all windows open by the user (option -list).
    * Set a specific window to "Always on Top" mode (option -top).
    * Set a specific window to "Normal" mode (option -normal).

## Usage

### List all windows

To list all open windows, run the following command:

```$ stickyTop -list```

### Set a window to "Always on Top" mode

To set a specific window to "Always on Top" mode, run the following command, replacing <window_title> with the title of the window you want to modify:


```$ stickyTop -top <window_title>```

### Set a window to "Normal" mode

To set a specific window to "Normal" mode, run the following command, replacing <window_title> with the title of the window you want to modify:


```$ stickyTop -normal <window_title>```

## Example

Here's an example of how to use the stickyTop program:


```$ stickyTop -top "Microsoft Edge"```



```$ stickyTop -normal "Microsoft Edge"```

## Dependencies

The stickyTop program uses the following libraries:

    * Windows.h
    * stdio.h
    * string.h
    
## To DO

   * Fix the encoding issue when listing windows.
   * Add a GUI.

## License 

The code is licensed under "CC BY-SA 2.0 FR"\
but the icon of the compiled file is private and cannot be reused.

For more information, see https://creativecommons.org/licenses/by-sa/2.0/fr/
