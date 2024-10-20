# Ferris sweep

![Ferris sweep, top view](https://i.imgur.com/5qCZUv6h.jpg)
![Ferris sweep, bottom view](https://i.imgur.com/ZC47CJth.jpg)

A version of the Ferris keyboard that uses a daughterboard, designed by the fantastic @davidphilipbarr with some input from @pierrechevalier83 for the copper pad. All PCB files are available on the [project's github page](https://github.com/davidphilipbarr/Sweep)

## Keyboard Info

* Keyboard Maintainer: [Pierre Chevalier](https://github.com/pierrechevalier83)
* Hardware Supported: [Sweep](https://github.com/davidphilipbarr/Sweep) (all versions)

Make example for this keyboard (after setting up your build environment):

    make ferris/sweep2_rp2040:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Builder's note: I started with a fresh clone of the QMK repository, dated as of 2024/10/19.  You may run into issues with other clones from late 2022 or earlier, especially since the RP2040 split configurations were not as stable (and not easy to compile) until mid-2023.

## Copying The Config

Once you've set up your QMK build environment, copy the folder "sweep2_rp2040" from this repository into directory "qmk_firmware/keyboards/ferris/".  You should have a new sub-configuration named "sweep2_rp2040" which is what you should use to build the firmware.  Once you do this, the full name of the keyboard configuration will be "ferris/sweep2_rp2040".

## Using RP2040 Controllers

Pro Micro RP2040 controllers are supported natively.

From directory "qmk_firmware", run either of these commands, depending on which side is plugged in and ready to accept firmware (i.e., in bootloader mode):

    make ferris/sweep2_rp2040:default:uf2-split-left      # (for left side)
    make ferris/sweep2_rp2040:default:uf2-split-right     # (for right side)

The QMK "converters" are not needed.  This keyboard config uses RP2040 natively.

Note: When using the "uf2-split-" options, you will need to plug in ONE SIDE at a time (i.e., without the TRRS cable) and then enter bootloader mode.

Note: I don't think it actually matters whether you get the "left" and "right" sides correct, since (apparently) each RP2040 controller can detect whether it is the "main" (with USB) or "peripheral" (without USB).  Nevertheless, it's probably safe to use the commands provided with the correct side.

## Hardware Testing

In the commands above, you can replace "default" with any other keymap that exists in the "ferris/keymaps" directory tree.  I used the "test" keymap, and the commands were as follows:

    make ferris/sweep2_rp2040:test:uf2-split-left      # (for left side)
    make ferris/sweep2_rp2040:test:uf2-split-right     # (for right side)

You can also make your own keymap by creating a new subdirectory in "ferris/keymaps" and customizing the files to match your needs.
    
## Bootloader

Enter bootloader mode in one of 2 ways:

* **Physical reset button**: Press and hold the RESET button soldered on the PCB, for at least 1 second.  The included controller is a Sea-Picro which only requires the RESET button to enter bootloader mode.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is configured.

If you are using other RP2040 boards that have both BOOT and RESET buttons available, then you will probably need to do the BOOT+RESET sequence:

1 - Press and hold BOOT button
2 - Press RESET button and then release it
3 - Release the BOOT button

As mentioned above and in the [Sea-Picro documentation](https://github.com/joshajohnson/sea-picro), the Sea-Picro board does not need this, since it has the improved BOOT+RESET circuit.  Simply hold down the RESET button for at least 1 second, then release it.

The reason I chose the Sea-Picro is because (A) it has the improved BOOT+RESET circuit, which only uses one button; and (B) other RP2040 boards usually have the BOOT and RESET buttons installed on the top side.  Since the Ferris Sweep requires the boards to be mounted top-side down, these buttons are not accessible.  While it is possible to take out the board before reflashing it (since the board is socketed), I don't advise doing this too many times.

Note: If you wish to leave bootloader mode WITHOUT updating the firmware, you can either (1) tap the RESET button for less than half a second, or (2) simply un-plug and re-plug the USB-C cable.  The RP2040 will return to its last uploaded firmware on a reset or power-cycle.

Note: The Sea-Picro boards were [purchased from Beekeeb](https://shop.beekeeb.com/product/sea-picro/) and they will look a bit different from the pictures of Sea-Picro boards on the Sea-Picro page.  This is OK.

Once you have entered bootloader mode, you will see a USB flash drive (i.e., mass storage device) appear with the name "RPI-RP2".  Then you can either use the "make" command with the "uf2-split-" option, or you can find the UF2 file and copy it manually to the "RPI-RP2" drive.  Either way works the same.  Once the UF2 file has been copied, the RP2040 will reset itself automatically and start using the new firmware that you just uploaded.

