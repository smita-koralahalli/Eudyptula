#include <linux/usb.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hid.h>

/*USB endpoints are bundled up into interfaces. USB interfaces handle only one type of
a USB logical connection, such as a mouse, a keyboard, or a audio stream*/
/*int (*probe) (struct usb_interface *intf, const struct usb_device_id *id)
Pointer to the probe function in the USB driver. This function (described in the
section “probe and disconnect in Detail”) is called by the USB core when it
thinks it has a struct usb_interface that this driver can handle. A pointer to the
struct usb_device_id that the USB core used to make this decision is also passed
to this function. If the USB driver claims the struct usb_interface that is passed
to it, it should initialize the device properly and return 0 . If the driver does not
want to claim the device, or an error occurs, it should return a negative error
value.*/
static int usbkeyboard_probe(struct usb_interface *interface,
		const struct usb_device_id *id)
{
	pr_info("USB keyboard connected\n"); //pr_alert//
	return 0;
}

/*USB Interface has been removed*/
static void usbkeyboard_disconnect(struct usb_interface *interface)
{
	pr_info("USB keyboard disconnected.\n");
}

/*The struct usb_device_id structure provides a list of different types of USB devices
that this driver supports*/

static const struct usb_device_id id_table[] = {
	{USB_INTERFACE_INFO
	 (USB_INTERFACE_CLASS_HID, USB_INTERFACE_SUBCLASS_BOOT,
	  USB_INTERFACE_PROTOCOL_KEYBOARD)},
	{},
};

MODULE_DEVICE_TABLE(usb, id_table);
/*the MODULE_DEVICE_TABLE macro is necessary to allow user-space
tools to figure out what devices this driver can control*/

/*DEscription of usb driver*/
static struct usb_driver usbkeyboard_driver = {
	.name = "usbkeyboard",
	.probe = usbkeyboard_probe,
	.disconnect = usbkeyboard_disconnect,
	.id_table = id_table,  //Pointer to the struct usb_device_id table that contains a list of all of the different kinds of USB devices this driver can accept//
};

/*To register a device usb_register is called with pointer to struct usb_driver*/
static int __init hello_init(void)
{
	printk(KERN_INFO "Hello World!\n");  //pr_debug
	int result;
	/* register this driver with the USB subsystem */
	result = usb_register(&usbkeyboard_driver);
	if (result)
	pr_err("usbkeyboard register failed. Error number %d", result);
	return result;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Good Bye Smita\n");
	usb_deregister(&usbkeyboard_driver);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Smita");
MODULE_DESCRIPTION("Keyboard USB Module");
