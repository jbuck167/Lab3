// Author: Josh Buck
// Course: CPS 471

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <string>

//#include <winsock2.h> // My laptop will not build this file for some reason, get lots of redefinition errors
//#include <iphlpapi.h>

// Link with Iphlpapi.lib
//#pragma comment(lib, "IPHLPAPI.lib")

#define WORKING_BUFFER_SIZE 15000
#define MAX_TRIES 3

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

using namespace std;

int main(int argc, char** argv) {

	// Generate Password 1:
	// The Password Key is "ABCDEF123456"
	std::string pw1 = "", pw1_key = "ABCDEF123456";
	for (char c : pw1_key) {
		c += 5;
		pw1.push_back(c);
	}
	std::cout << "Password 1: " << pw1 << endl;

	// Generate Password 2:
	// The Password Key is "ARCHIEMILLER"
	std::string pw2 = "", pw2_key = "ARCHIEMILLER";
	int i = 0;
	for (char c : pw2_key) {
		c -= i;
		pw2.push_back(c);
		i++;
	}
	std::cout << "Password 2: " << pw2 << endl;

	// Generate Password 3:
	// The Password Key is "GO FLYERS!!!"
	std::string pw3 = "", pw3_key = "GO FLYERS!!!";
	int j = 0;
	for (char c : pw3_key) {
		c ^= j;
		pw3.push_back(c);
		j++;
	}
	std::cout << "Password 3: " << pw3 << endl;

	// Generate Password 4:
	// The password is simply the disk drive serial number
	DWORD pw4;
	GetVolumeInformationW(NULL, NULL, NULL, &pw4, NULL, NULL, NULL, NULL);
	std::cout << "Password 4: " << pw4 << endl;
	std::cout << "\tThis was not working for me...\n\tIs there another operation on this number to create the password? " << endl << endl;

	// Generate Password 5:
	/*
	ULONG WINAPI GetAdaptersAddresses(
  _In_    ULONG                 Family,
  _In_    ULONG                 Flags,
  _In_    PVOID                 Reserved,
  _Inout_ PIP_ADAPTER_ADDRESSES AdapterAddresses,
  _Inout_ PULONG                SizePointer
);

// matryoshka.exe uses arguments GetAdaptersAddresses(2, 0, 0, esi, eax)

	*/
	//ULONG outBufLen = 0;
	//ULONG Iterations = 0;
	//PIP_ADAPTER_ADDRESSES pAddresses = NULL;

	//// Allocate a 15 KB buffer to start with.
	//outBufLen = WORKING_BUFFER_SIZE;

	//pAddresses = (IP_ADAPTER_ADDRESSES *)MALLOC(outBufLen);
	//GetAdaptersAddresses(2, 0, 0, pAddresses, &outBufLen);

	//PIP_ADAPTER_ADDRESSES pCurrAddresses = NULL;
	//PIP_ADAPTER_UNICAST_ADDRESS pUnicast = NULL;
	//PIP_ADAPTER_ANYCAST_ADDRESS pAnycast = NULL;
	//PIP_ADAPTER_MULTICAST_ADDRESS pMulticast = NULL;
	//IP_ADAPTER_DNS_SERVER_ADDRESS *pDnServer = NULL;
	//IP_ADAPTER_PREFIX *pPrefix = NULL;

	    //pCurrAddresses = pAddresses;
     //   while (pCurrAddresses) {
     //       printf("\tLength of the IP_ADAPTER_ADDRESS struct: %ld\n",
     //              pCurrAddresses->Length);
     //       printf("\tIfIndex (IPv4 interface): %u\n", pCurrAddresses->IfIndex);
     //       printf("\tAdapter name: %s\n", pCurrAddresses->AdapterName);

     //       pUnicast = pCurrAddresses->FirstUnicastAddress;
     //       if (pUnicast != NULL) {
     //           for (i = 0; pUnicast != NULL; i++)
     //               pUnicast = pUnicast->Next;
     //           printf("\tNumber of Unicast Addresses: %d\n", i);
     //       } else
     //           printf("\tNo Unicast Addresses\n");

     //       pAnycast = pCurrAddresses->FirstAnycastAddress;
     //       if (pAnycast) {
     //           for (i = 0; pAnycast != NULL; i++)
     //               pAnycast = pAnycast->Next;
     //           printf("\tNumber of Anycast Addresses: %d\n", i);
     //       } else
     //           printf("\tNo Anycast Addresses\n");

     //       pMulticast = pCurrAddresses->FirstMulticastAddress;
     //       if (pMulticast) {
     //           for (i = 0; pMulticast != NULL; i++)
     //               pMulticast = pMulticast->Next;
     //           printf("\tNumber of Multicast Addresses: %d\n", i);
     //       } else
     //           printf("\tNo Multicast Addresses\n");

     //       pDnServer = pCurrAddresses->FirstDnsServerAddress;
     //       if (pDnServer) {
     //           for (i = 0; pDnServer != NULL; i++)
     //               pDnServer = pDnServer->Next;
     //           printf("\tNumber of DNS Server Addresses: %d\n", i);
     //       } else
     //           printf("\tNo DNS Server Addresses\n");

     //       printf("\tDNS Suffix: %wS\n", pCurrAddresses->DnsSuffix);
     //       printf("\tDescription: %wS\n", pCurrAddresses->Description);
     //       printf("\tFriendly name: %wS\n", pCurrAddresses->FriendlyName);

     //       if (pCurrAddresses->PhysicalAddressLength != 0) {
     //           printf("\tPhysical address: ");
     //           for (i = 0; i < (int) pCurrAddresses->PhysicalAddressLength;
     //                i++) {
     //               if (i == (pCurrAddresses->PhysicalAddressLength - 1))
     //                   printf("%.2X\n",
     //                          (int) pCurrAddresses->PhysicalAddress[i]);
     //               else
     //                   printf("%.2X-",
     //                          (int) pCurrAddresses->PhysicalAddress[i]);
     //           }
     //       }
     //       printf("\tFlags: %ld\n", pCurrAddresses->Flags);
     //       printf("\tMtu: %lu\n", pCurrAddresses->Mtu);
     //       printf("\tIfType: %ld\n", pCurrAddresses->IfType);
     //       printf("\tOperStatus: %ld\n", pCurrAddresses->OperStatus);
     //       printf("\tIpv6IfIndex (IPv6 interface): %u\n",
     //              pCurrAddresses->Ipv6IfIndex);
     //       printf("\tZoneIndices (hex): ");
     //       for (i = 0; i < 16; i++)
     //           printf("%lx ", pCurrAddresses->ZoneIndices[i]);
     //       printf("\n");

     //       printf("\tTransmit link speed: %I64u\n", pCurrAddresses->TransmitLinkSpeed);
     //       printf("\tReceive link speed: %I64u\n", pCurrAddresses->ReceiveLinkSpeed);

     //       pPrefix = pCurrAddresses->FirstPrefix;
     //       if (pPrefix) {
     //           for (i = 0; pPrefix != NULL; i++)
     //               pPrefix = pPrefix->Next;
     //           printf("\tNumber of IP Adapter Prefix entries: %d\n", i);
     //       } else
     //           printf("\tNumber of IP Adapter Prefix entries: 0\n");

     //       printf("\n");

     //       pCurrAddresses = pCurrAddresses->Next;
     //   }

	std::cout << "Password 5: " << "Cannot successfully obtain network address" << endl;
	std::cout << "\tThis was not working for me...\n\tIs there another operation on this number to create the password? " << endl << endl;


	std::cout << "Enter any character to close..." << endl;
	char c;
	cin >> c;

	return 0;
}