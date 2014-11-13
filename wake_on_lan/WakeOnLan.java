import java.io.*;
import java.net.*;

// Source of the original code: http://www.jibble.org/wake-on-lan/

// The payload comprises six bytes of 0xFF followed by sixteen repetitions
// of the target machine's MAC address, sent to the broadcast IP address on
// the LAN.

public class WakeOnLan {
    
    public static final int PORT = 9;    
    
    public static void main(String[] args) {
        
        if (args.length != 2) {
            System.out.println("Usage: java WakeOnLan <broadcast-ip> <mac-address>");
			System.out.println("       IP address may be numeric or DNS; MAC address");
			System.out.println("       should be delimited with colons or hyphens.");
            System.exit(1);
        }
        
        String ipStr = args[0];
        String macStr = args[1];
        
        try {
            byte[] macBytes = getMacBytes(macStr);
            byte[] bytes = new byte[6 + 16 * macBytes.length];
            for (int i = 0; i < 6; i++) {
                bytes[i] = (byte) 0xff;
            }
            for (int i = 6; i < bytes.length; i += macBytes.length) {
                System.arraycopy(macBytes, 0, bytes, i, macBytes.length);
            }
            
            InetAddress address = InetAddress.getByName(ipStr);
            DatagramPacket packet = new DatagramPacket(bytes, bytes.length, address, PORT);
            DatagramSocket socket = new DatagramSocket();
            socket.send(packet);
            socket.close();
            
            System.out.println("Wake-on-LAN packet sent to MAC addr " + macStr
                + " via IP " + address.getHostAddress() + ".");
        }
        catch (Exception e) {
            System.out.println("Failed to send Wake-on-LAN packet: " + e);
            System.exit(1);
        }
    }
    
    private static byte[] getMacBytes(String macStr) throws IllegalArgumentException {
        byte[] bytes = new byte[6];
        String[] hex = macStr.split("(\\:|\\-)");
        if (hex.length != 6) {
            throw new IllegalArgumentException("\"" + macStr + "\""
                + " is not the right length to be a MAC address.");
        }
        try {
            for (int i = 0; i < 6; i++) {
                bytes[i] = (byte) Integer.parseInt(hex[i], 16);
            }
        }
        catch (NumberFormatException e) {
            throw new IllegalArgumentException("Invalid hex digit in MAC address.");
        }
        return bytes;
    }
}

