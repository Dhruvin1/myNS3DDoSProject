/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
     /*
      * This program is free software; you can redistribute it and/or modify
      * it under the terms of the GNU General Public License version 2 as
      * published by the Free Software Foundation;
      *
      * This program is distributed in the hope that it will be useful,
      * but WITHOUT ANY WARRANTY; without even the implied warranty of
      * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     * GNU General Public License for more details.
     *
     * You should have received a copy of the GNU General Public License
     * along with this program; if not, write to the Free Software
     * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
     *
     */
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "ns3/olsr-helper.h"
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/netanim-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/csma-module.h"
#include "ns3/applications-module.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/point-to-point-layout-module.h"
#include "ns3/flow-monitor-helper.h"
#include "string.h"


    
    // Network topology (default)
    //
    //        n2 n3 n4              .
    //         \ | /                .
    //          \|/                 .
    //     n1--- n0---n5            .
    //          /|\                 .
    //         / | \                .
    //        n8 n7 n6              .
   //
    
    
using namespace ns3;
using namespace std;    
NS_LOG_COMPONENT_DEFINE ("Star");

    void handler (int i)
        {
       cout<<"inside handler"<<endl;
        }
int main (int argc, char *argv[])
    {
      double myRandomNo;
      int randNo;
      cout << "All included, inside main()" << endl;
      //
      // Set up some default values for the simulation.
      //
      Config::SetDefault ("ns3::OnOffApplication::PacketSize", UintegerValue (137));
    
      // ??? try and stick 15kb/s into the data rate
      Config::SetDefault ("ns3::OnOffApplication::DataRate", StringValue ("40kb/s"));
    
      //
      // Default number of nodes in the star.  Overridable by command line argument.
      //
      uint32_t nSpokes = 10;
      uint32_t nCsma = 3;
    
      CommandLine cmd;
      cmd.AddValue ("nSpokes", "Number of nodes to place in the star", nSpokes);
      cmd.Parse (argc, argv);
    
        //Building two star topologies
      NS_LOG_INFO ("Build star topology.");
      PointToPointHelper pointToPoint;
      
      pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("1Gbps"));
      pointToPoint.SetChannelAttribute ("Delay", StringValue ("2ms"));
      PointToPointStarHelper star1 (nSpokes, pointToPoint);
      PointToPointStarHelper star2 (nSpokes, pointToPoint);
      PointToPointStarHelper star3 (nSpokes, pointToPoint);
      PointToPointStarHelper star4 (nSpokes, pointToPoint);
      PointToPointStarHelper star5 (nSpokes, pointToPoint);
      PointToPointStarHelper star6 (nSpokes, pointToPoint);
      PointToPointStarHelper star7 (nSpokes, pointToPoint);
      PointToPointStarHelper star8 (nSpokes, pointToPoint);
      PointToPointStarHelper star9 (nSpokes, pointToPoint);
      PointToPointStarHelper star10 (nSpokes, pointToPoint);
      PointToPointStarHelper star11 (nSpokes, pointToPoint);
      PointToPointStarHelper star12 (nSpokes, pointToPoint);
      PointToPointStarHelper star13 (nSpokes, pointToPoint);
      PointToPointStarHelper star14 (nSpokes, pointToPoint);
      PointToPointStarHelper star15 (nSpokes, pointToPoint);
      PointToPointStarHelper star16 (nSpokes, pointToPoint);
      PointToPointStarHelper star17 (nSpokes, pointToPoint);
      PointToPointStarHelper star18 (nSpokes, pointToPoint);
      PointToPointStarHelper star19 (nSpokes, pointToPoint);
      PointToPointStarHelper star20 (nSpokes, pointToPoint);
      PointToPointStarHelper star21 (nSpokes, pointToPoint);
      PointToPointStarHelper star22 (nSpokes, pointToPoint);
      PointToPointStarHelper star23 (nSpokes, pointToPoint);
      PointToPointStarHelper star24 (nSpokes, pointToPoint);
      PointToPointStarHelper star25 (nSpokes, pointToPoint);

        //Nodes for Network backbone
        NodeContainer p2pNodes, p2pNodes1,p2pNodes2, p2pNodes3,p2pNodes4, p2pNodes5, p2pBB;
        NodeContainer p2pNodes6, p2pNodes7, p2pNodes8, p2pNodes9, p2pNodes10, p2pNodes11;
        NodeContainer p2pNodes12, p2pNodes13, p2pNodes14, p2pNodes15, p2pNodes16, p2pNodes17;
        NodeContainer p2pNodes18, p2pNodes19, p2pNodes20, p2pNodes21, p2pNodes22, p2pNodes23;
        NodeContainer p2pNodes24, p2pNodes25, p2pNodes26, p2pNodes27, p2pNodes28, p2pNodes29;
        NodeContainer p2pNodes30, p2pNodes31, p2pNodes32, p2pNodes33, p2pNodes34, p2pNodes35;
        NodeContainer p2pNodes36, p2pNodes37, p2pNodes38, p2pNodes39, p2pNodes40, p2pNodes41;
        NodeContainer p2pNodes42, p2pNodes43, p2pNodes44, p2pNodes45;
        //Nodes on cloud network
        NodeContainer c1,c2,c3,c4;
        NodeContainer l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
        c1.Create(1);
        c2.Create(1);
        c3.Create(1);
        c4.Create(1);
        l1.Create(1);
        l2.Create(1);
        l3.Create(1);
        l4.Create(1);
        l5.Create(1);
        l6.Create(1);
        l7.Create(1);
        l8.Create(1);
        l9.Create(1);
        l10.Create(1);
        
        NodeContainer n1 = NodeContainer (c1,l1);
        NodeContainer n2 = NodeContainer (c2,l2);
        NodeContainer n3 = NodeContainer (c3,l3);
        NodeContainer n4 = NodeContainer (c4,l4);

        NodeContainer n51 = NodeContainer (l5,l1);
        NodeContainer n52 = NodeContainer (l5,l2);

        NodeContainer n61 = NodeContainer (l6,l1);
        NodeContainer n62 = NodeContainer (l6,l2);

        NodeContainer n71 = NodeContainer (l7,l3);
        NodeContainer n72 = NodeContainer (l7,l4);

        NodeContainer n81 = NodeContainer (l8,l3);
        NodeContainer n82 = NodeContainer (l8,l4);

        NodeContainer n91 = NodeContainer (l9,l5);
        NodeContainer n92 = NodeContainer (l9,l7);

        NodeContainer nx = NodeContainer (l10,l6);
        NodeContainer ny = NodeContainer (l10,l8);


        //Point to point nodes in outer network
        //p2pNodes.Add(star1.GetHub());
        //p2pNodes.Add(star2.GetHub());
        p2pNodes.Create (2);
        
        p2pNodes1.Add(star1.GetHub());
        p2pNodes1.Add(p2pNodes.Get(1));
        
        p2pNodes2.Add(star2.GetHub());
        p2pNodes2.Add(p2pNodes.Get(0));
        
        p2pNodes3.Add(star3.GetHub());
        p2pNodes3.Add(p2pNodes.Get(0));
        
        p2pNodes4.Add(star4.GetHub());
        p2pNodes4.Add(p2pNodes.Get(1));
        
        p2pBB.Add(p2pNodes.Get(1));
        p2pBB.Create(1);
        
        p2pNodes5.Add(star5.GetHub());
        p2pNodes5.Add(p2pBB.Get(1));


        p2pNodes6.Create (2);
        
        p2pNodes7.Add(star6.GetHub());
        p2pNodes7.Add(p2pNodes6.Get(1));
        
        p2pNodes8.Add(star7.GetHub());
        p2pNodes8.Add(p2pNodes6.Get(0));
        
        p2pNodes9.Add(star8.GetHub());
        p2pNodes9.Add(p2pNodes6.Get(0));
        
        p2pNodes10.Add(star9.GetHub());
        p2pNodes10.Add(p2pNodes6.Get(1));
        
        p2pNodes11.Add(star10.GetHub());
        p2pNodes11.Add(p2pNodes6.Get(1));

        p2pNodes12.Create(1);

        p2pNodes13.Add(p2pNodes.Get(0));
        p2pNodes13.Add(p2pNodes12.Get(0));

        p2pNodes14.Add(p2pNodes6.Get(0));
        p2pNodes14.Add(p2pNodes12.Get(0));

        //p2pNodes15.Add(l9.Get(0));
        //p2pNodes15.Add(p2pNodes12.Get(0));

        p2pNodes16.Add(l10.Get(0));
        p2pNodes16.Add(p2pNodes12.Get(0));

        p2pNodes17.Create(2);
        
        p2pNodes18.Add(p2pNodes.Get(0));
        p2pNodes18.Add(p2pNodes17.Get(0));
        
        p2pNodes19.Add(p2pNodes6.Get(0));
        p2pNodes19.Add(p2pNodes17.Get(1));
        
        p2pNodes20.Add(l9.Get(0));
        p2pNodes20.Add(p2pNodes17.Get(0));

        //p2pNodes21.Add(l10.Get(0));
        //p2pNodes21.Add(p2pNodes17.Get(0));

        //p2pNodes22.Add(l9.Get(0));
        //p2pNodes22.Add(p2pNodes17.Get(1));

        p2pNodes23.Add(l10.Get(0));
        p2pNodes23.Add(p2pNodes17.Get(1));

        p2pNodes24.Create(6);

        p2pNodes25.Add(p2pNodes24.Get(0));
        p2pNodes25.Add(p2pNodes24.Get(1));

        p2pNodes26.Add(p2pNodes24.Get(2));
        p2pNodes26.Add(p2pNodes24.Get(3));

        p2pNodes27.Add(p2pNodes24.Get(4));
        p2pNodes27.Add(p2pNodes24.Get(5));
      
        p2pNodes28.Add(star12.GetHub());
        p2pNodes28.Add(p2pNodes24.Get(0));

        p2pNodes29.Add(star11.GetHub());
        p2pNodes29.Add(p2pNodes24.Get(1));

        p2pNodes30.Add(star13.GetHub());
        p2pNodes30.Add(p2pNodes24.Get(0));

        p2pNodes31.Add(star14.GetHub());
        p2pNodes31.Add(p2pNodes24.Get(1));

        p2pNodes32.Add(star15.GetHub());
        p2pNodes32.Add(p2pNodes24.Get(1));

        p2pNodes33.Add(star17.GetHub());
        p2pNodes33.Add(p2pNodes24.Get(2));

        p2pNodes34.Add(star16.GetHub());
        p2pNodes34.Add(p2pNodes24.Get(3));

        p2pNodes35.Add(star18.GetHub());
        p2pNodes35.Add(p2pNodes24.Get(2));

        p2pNodes36.Add(star19.GetHub());
        p2pNodes36.Add(p2pNodes24.Get(3));

        p2pNodes37.Add(star20.GetHub());
        p2pNodes37.Add(p2pNodes24.Get(3));

        p2pNodes38.Add(star22.GetHub());
        p2pNodes38.Add(p2pNodes24.Get(4));

        p2pNodes39.Add(star21.GetHub());
        p2pNodes39.Add(p2pNodes24.Get(5));

        p2pNodes40.Add(star23.GetHub());
        p2pNodes40.Add(p2pNodes24.Get(4));

        p2pNodes41.Add(star24.GetHub());
        p2pNodes41.Add(p2pNodes24.Get(5));

        p2pNodes42.Add(star25.GetHub());
        p2pNodes42.Add(p2pNodes24.Get(5));

        p2pNodes43.Add(p2pNodes17.Get(1));
        p2pNodes43.Add(p2pNodes24.Get(0));

        p2pNodes44.Add(p2pNodes17.Get(0));
        p2pNodes44.Add(p2pNodes24.Get(2));

        p2pNodes45.Add(p2pNodes17.Get(1));
        p2pNodes45.Add(p2pNodes24.Get(4));

        //Install point to point services in backbone nodes
        
        NetDeviceContainer p2pDevices,p2pDevices1,p2pDevices2,p2pDevices3,p2pDevices4,p2pDevices5;
        NetDeviceContainer p2pDevices6,p2pDevices7,p2pDevices8,p2pDevices9,p2pDevices10,p2pDevices11,p2pDevices12;
        NetDeviceContainer p2pDevices13, p2pDevices14, p2pDevices15, p2pDevices16, p2pDevices17;
        NetDeviceContainer p2pDevices18, p2pDevices19, p2pDevices20, p2pDevices21, p2pDevices22, p2pDevices23;
        NetDeviceContainer p2pDevices42, p2pDevices25, p2pDevices26, p2pDevices27, p2pDevices28, p2pDevices29;
        NetDeviceContainer p2pDevices30, p2pDevices31, p2pDevices32, p2pDevices33, p2pDevices34, p2pDevices35;
        NetDeviceContainer p2pDevices36, p2pDevices37, p2pDevices38, p2pDevices39, p2pDevices40, p2pDevices41;
        NetDeviceContainer p2pDevices43, p2pDevices44, p2pDevices45;
        p2pDevices = pointToPoint.Install (p2pNodes);
        p2pDevices1 = pointToPoint.Install (p2pNodes1);
        p2pDevices2 = pointToPoint.Install (p2pNodes2);
        p2pDevices3 = pointToPoint.Install (p2pNodes3);
        p2pDevices4 = pointToPoint.Install (p2pNodes4);
        p2pDevices5 = pointToPoint.Install (p2pNodes5);

        p2pDevices6 = pointToPoint.Install (p2pNodes6);
        p2pDevices7 = pointToPoint.Install (p2pNodes7);
        p2pDevices8 = pointToPoint.Install (p2pNodes8);
        p2pDevices9 = pointToPoint.Install (p2pNodes9);
        p2pDevices10 = pointToPoint.Install (p2pNodes10);
        p2pDevices11 = pointToPoint.Install (p2pNodes11);
        p2pDevices12 = pointToPoint.Install (p2pBB);
        
        //p2pDevices13 = pointToPoint.Install (p2pNodes13);
        p2pDevices14 = pointToPoint.Install (p2pNodes14);
        //p2pDevices15 = pointToPoint.Install (p2pNodes15);
        p2pDevices16 = pointToPoint.Install (p2pNodes16);
        
        p2pDevices18 = pointToPoint.Install (p2pNodes18);

        p2pDevices19 = pointToPoint.Install (p2pNodes19);
        p2pDevices20 = pointToPoint.Install (p2pNodes20);
        //p2pDevices21 = pointToPoint.Install (p2pNodes21);
        //p2pDevices22 = pointToPoint.Install (p2pNodes22);
        p2pDevices23 = pointToPoint.Install (p2pNodes23);

        //p2pDevices24 = pointToPoint.Install (p2pNodes24);
        p2pDevices25 = pointToPoint.Install (p2pNodes25);
        p2pDevices26 = pointToPoint.Install (p2pNodes26);
        p2pDevices27 = pointToPoint.Install (p2pNodes27);
        p2pDevices28 = pointToPoint.Install (p2pNodes28);

        p2pDevices29 = pointToPoint.Install (p2pNodes29);
        p2pDevices30 = pointToPoint.Install (p2pNodes30);
        p2pDevices31 = pointToPoint.Install (p2pNodes31);
        p2pDevices32 = pointToPoint.Install (p2pNodes32);
        p2pDevices33 = pointToPoint.Install (p2pNodes33);

        p2pDevices34 = pointToPoint.Install (p2pNodes34);
        p2pDevices35 = pointToPoint.Install (p2pNodes35);
        p2pDevices36 = pointToPoint.Install (p2pNodes36);
        p2pDevices37 = pointToPoint.Install (p2pNodes37);
        p2pDevices38 = pointToPoint.Install (p2pNodes38);

        p2pDevices39 = pointToPoint.Install (p2pNodes39);
        p2pDevices40 = pointToPoint.Install (p2pNodes40);
        p2pDevices41 = pointToPoint.Install (p2pNodes41);
        p2pDevices42 = pointToPoint.Install (p2pNodes42);
        
        p2pDevices43 = pointToPoint.Install (p2pNodes43);
        p2pDevices44 = pointToPoint.Install (p2pNodes44);
        p2pDevices45 = pointToPoint.Install (p2pNodes45);

        //Building csma topology connected to star1 network
      NodeContainer csmaNodes;
      csmaNodes.Add (star1.GetHub());
      csmaNodes.Create (nCsma);
      CsmaHelper csma;
      csma.SetChannelAttribute ("DataRate", StringValue ("1Mbps"));
      csma.SetChannelAttribute ("Delay", StringValue ("2ms"));
      NetDeviceContainer csmaDevices;
      csmaDevices = csma.Install (csmaNodes);
    
      //Installing internet stack in nodes
      NS_LOG_INFO ("Install internet stack on all nodes.");
      InternetStackHelper internet;
      star1.InstallStack (internet);
      star2.InstallStack (internet);
      star3.InstallStack (internet);
      star4.InstallStack (internet);
      star5.InstallStack (internet);
      star6.InstallStack (internet);
      star7.InstallStack (internet);
      star8.InstallStack (internet);
      star9.InstallStack (internet);
      star10.InstallStack (internet);
      star11.InstallStack (internet);
      star12.InstallStack (internet);
      star13.InstallStack (internet);
      star14.InstallStack (internet);
      star15.InstallStack (internet);
      star16.InstallStack (internet);
      star17.InstallStack (internet);
      star18.InstallStack (internet);
      star19.InstallStack (internet);
      star20.InstallStack (internet);
      star21.InstallStack (internet);
      star22.InstallStack (internet);
      star23.InstallStack (internet);
      star24.InstallStack (internet);
      star25.InstallStack (internet);
      InternetStackHelper stack;
      stack.Install (p2pNodes.Get(0));
      stack.Install (p2pNodes.Get(1));
      stack.Install (p2pBB.Get(1));
      stack.Install (p2pNodes6.Get(0));
      stack.Install (p2pNodes6.Get(1));
      stack.Install (p2pNodes12.Get(0));
      stack.Install (p2pNodes17.Get(0));
      stack.Install (p2pNodes17.Get(1));

      stack.Install (p2pNodes24.Get(0));
      stack.Install (p2pNodes24.Get(1));
      stack.Install (p2pNodes24.Get(2));
      stack.Install (p2pNodes24.Get(3));
      stack.Install (p2pNodes24.Get(4));
      stack.Install (p2pNodes24.Get(5));
      



      // Installing internet on cloud nodes
      internet.Install (c1);
      internet.Install (c2);
      internet.Install (c3);
          internet.Install (c4);
          internet.Install (l1);
          internet.Install (l2);
          internet.Install (l3);
          internet.Install (l4);
          internet.Install (l5);
          internet.Install (l6);
          internet.Install (l7);
          internet.Install (l8);
          internet.Install (l9);
          internet.Install (l10);
     
      //stack.Install (star.GetHub());
      for(uint32_t i=1; i<=nCsma; i++)
      {
      stack.Install (csmaNodes.Get(i));
      }
    
        //creating channels in cloud nodes
        
        

          PointToPointHelper p2p;
          p2p.SetDeviceAttribute ("DataRate", StringValue ("1Mbps"));
          p2p.SetChannelAttribute ("Delay", StringValue ("2ms"));
          
        NetDeviceContainer d1 = p2p.Install (n1 );
        NetDeviceContainer d2 = p2p.Install (n2 );
        NetDeviceContainer d3 = p2p.Install (n3 );
        NetDeviceContainer d4 = p2p.Install (n4 );
          NetDeviceContainer d51 = p2p.Install(n51);
          NetDeviceContainer d52 = p2p.Install(n52);
          NetDeviceContainer d61 = p2p.Install(n61);
          NetDeviceContainer d62 = p2p.Install(n62);
          NetDeviceContainer d71 = p2p.Install(n71);
          NetDeviceContainer d72 = p2p.Install(n72);
          NetDeviceContainer d81 = p2p.Install(n81);
          NetDeviceContainer d82 = p2p.Install(n82);
          NetDeviceContainer d91 = p2p.Install(n91);
          NetDeviceContainer d92 = p2p.Install(n92);
          NetDeviceContainer dx = p2p.Install(nx);
          NetDeviceContainer dy = p2p.Install(ny);
          cout << "Control after point-to-point" << endl;

        //Assigning ip addresses
        NS_LOG_INFO ("Assign IP Addresses.");
        star1.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.1.0", "255.255.255.252"));
        star2.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.2.0", "255.255.255.252"));
        star3.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.3.0", "255.255.255.252"));
        star4.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.4.0", "255.255.255.252"));
        star5.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.5.0", "255.255.255.252"));
        star6.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.6.0", "255.255.255.252"));
        star7.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.7.0", "255.255.255.252"));
        star8.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.8.0", "255.255.255.252"));
        star9.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.9.0", "255.255.255.252"));
        star10.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.10.0", "255.255.255.252"));
        star11.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.11.0", "255.255.255.252"));
        star12.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.12.0", "255.255.255.252"));
        star13.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.13.0", "255.255.255.252"));
        star14.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.14.0", "255.255.255.252"));
        star15.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.15.0", "255.255.255.252"));
        star16.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.16.0", "255.255.255.252"));
        star17.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.17.0", "255.255.255.252"));
        star18.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.18.0", "255.255.255.252"));
        star19.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.19.0", "255.255.255.252"));
        star20.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.20.0", "255.255.255.252"));
        star21.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.21.0", "255.255.255.252"));
        star22.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.22.0", "255.255.255.252"));
        star23.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.23.0", "255.255.255.252"));
        star24.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.24.0", "255.255.255.252"));
        star25.AssignIpv4Addresses (Ipv4AddressHelper ("10.2.25.0", "255.255.255.252"));
        Ipv4AddressHelper address;
        Ipv4InterfaceContainer p2pInterfaces,p2pInterfaces1,p2pInterfaces2,p2pInterfaces3,p2pInterfaces4,p2pInterfaces5, p2pInterfaces6;
        Ipv4InterfaceContainer p2pInterfaces7,p2pInterfaces8,p2pInterfaces9,p2pInterfaces10,p2pInterfaces11,p2pInterfaces12;
        Ipv4InterfaceContainer p2pInterfaces13,p2pInterfaces14,p2pInterfaces15,p2pInterfaces16, p2pInterfaces17;
        Ipv4InterfaceContainer p2pInterfaces18,p2pInterfaces19,p2pInterfaces20,p2pInterfaces21,p2pInterfaces22,p2pInterfaces23;
        Ipv4InterfaceContainer p2pInterfaces25,p2pInterfaces26, p2pInterfaces27,p2pInterfaces40,p2pInterfaces41,p2pInterfaces42;
        Ipv4InterfaceContainer p2pInterfaces28,p2pInterfaces29,p2pInterfaces30,p2pInterfaces31,p2pInterfaces32,p2pInterfaces33;
        Ipv4InterfaceContainer p2pInterfaces34,p2pInterfaces35,p2pInterfaces36,p2pInterfaces37,p2pInterfaces38,p2pInterfaces39;
        Ipv4InterfaceContainer p2pInterfaces43,p2pInterfaces44,p2pInterfaces45;
        address.SetBase ("10.2.50.0", "255.255.255.252");
        p2pInterfaces = address.Assign (p2pDevices);
        address.SetBase ("10.2.51.0", "255.255.255.252");
        p2pInterfaces1 = address.Assign (p2pDevices1);
        address.SetBase ("10.2.52.0", "255.255.255.252");
        p2pInterfaces2 = address.Assign (p2pDevices2);
        address.SetBase ("10.2.53.0", "255.255.255.252");
        p2pInterfaces3 = address.Assign (p2pDevices3);
        address.SetBase ("10.2.54.0", "255.255.255.252");
        p2pInterfaces4 = address.Assign (p2pDevices4);
        address.SetBase ("10.2.55.0", "255.255.255.252");
        p2pInterfaces5 = address.Assign (p2pDevices5);
        address.SetBase ("10.2.56.0", "255.255.255.252");
        p2pInterfaces6 = address.Assign (p2pDevices6);
        address.SetBase ("10.2.57.0", "255.255.255.252");
        p2pInterfaces7 = address.Assign (p2pDevices7);
        address.SetBase ("10.2.58.0", "255.255.255.252");
        p2pInterfaces8 = address.Assign (p2pDevices8);
        address.SetBase ("10.2.59.0", "255.255.255.252");
        p2pInterfaces9 = address.Assign (p2pDevices9);
        address.SetBase ("10.2.60.0", "255.255.255.252");
        p2pInterfaces10 = address.Assign (p2pDevices10);
        address.SetBase ("10.2.61.0", "255.255.255.252");
        p2pInterfaces11 = address.Assign (p2pDevices11);
        address.SetBase ("10.2.62.0", "255.255.255.252");
        p2pInterfaces12 = address.Assign (p2pDevices12);
        address.SetBase ("10.2.63.0", "255.255.255.252");
        p2pInterfaces13 = address.Assign (p2pDevices13);
        address.SetBase ("10.2.64.0", "255.255.255.252");
        p2pInterfaces14 = address.Assign (p2pDevices14);
        //address.SetBase ("10.2.65.0", "255.255.255.252");
        //p2pInterfaces15 = address.Assign (p2pDevices15);
        address.SetBase ("10.2.66.0", "255.255.255.252");
        p2pInterfaces16 = address.Assign (p2pDevices16);
        address.SetBase ("10.2.67.0", "255.255.255.252");
        p2pInterfaces17 = address.Assign (p2pDevices17);
        address.SetBase ("10.2.68.0", "255.255.255.252");
        p2pInterfaces18 = address.Assign (p2pDevices18);
        address.SetBase ("10.2.69.0", "255.255.255.252");
        p2pInterfaces19 = address.Assign (p2pDevices19);
        address.SetBase ("10.2.70.0", "255.255.255.252");
        p2pInterfaces20 = address.Assign (p2pDevices20);
        //address.SetBase ("10.2.71.0", "255.255.255.252");
        //p2pInterfaces21 = address.Assign (p2pDevices21);
        //address.SetBase ("10.2.72.0", "255.255.255.252");
        //p2pInterfaces22 = address.Assign (p2pDevices22);
        address.SetBase ("10.2.73.0", "255.255.255.252");
        p2pInterfaces23 = address.Assign (p2pDevices23);
        //address.SetBase ("10.2.74.0", "255.255.255.252");
        //p2pInterfaces24 = address.Assign (p2pDevices14);
        address.SetBase ("10.2.75.0", "255.255.255.252");
        p2pInterfaces25 = address.Assign (p2pDevices25);
        address.SetBase ("10.2.76.0", "255.255.255.252");
        p2pInterfaces26 = address.Assign (p2pDevices26);
        address.SetBase ("10.2.77.0", "255.255.255.252");
        p2pInterfaces27 = address.Assign (p2pDevices27);
        address.SetBase ("10.2.78.0", "255.255.255.252");
        p2pInterfaces28 = address.Assign (p2pDevices28);
        address.SetBase ("10.2.79.0", "255.255.255.252");
        p2pInterfaces29 = address.Assign (p2pDevices29);
        address.SetBase ("10.2.80.0", "255.255.255.252");
        p2pInterfaces30 = address.Assign (p2pDevices30);
        address.SetBase ("10.2.81.0", "255.255.255.252");
        p2pInterfaces31 = address.Assign (p2pDevices31);
        address.SetBase ("10.2.82.0", "255.255.255.252");
        p2pInterfaces32 = address.Assign (p2pDevices32);
        address.SetBase ("10.2.83.0", "255.255.255.252");
        p2pInterfaces33 = address.Assign (p2pDevices33);
        address.SetBase ("10.2.84.0", "255.255.255.252");
        p2pInterfaces34 = address.Assign (p2pDevices34);
        address.SetBase ("10.2.85.0", "255.255.255.252");
        p2pInterfaces35 = address.Assign (p2pDevices35);
        address.SetBase ("10.2.86.0", "255.255.255.252");
        p2pInterfaces36 = address.Assign (p2pDevices36);
        address.SetBase ("10.2.87.0", "255.255.255.252");
        p2pInterfaces37 = address.Assign (p2pDevices37);
        address.SetBase ("10.2.88.0", "255.255.255.252");
        p2pInterfaces38 = address.Assign (p2pDevices38);
        address.SetBase ("10.2.89.0", "255.255.255.252");
        p2pInterfaces39 = address.Assign (p2pDevices39);
        address.SetBase ("10.2.90.0", "255.255.255.252");
        p2pInterfaces40 = address.Assign (p2pDevices40);
        address.SetBase ("10.2.91.0", "255.255.255.252");
        p2pInterfaces41 = address.Assign (p2pDevices41);
        address.SetBase ("10.2.92.0", "255.255.255.252");
        p2pInterfaces42 = address.Assign (p2pDevices42);
        address.SetBase ("10.2.93.0", "255.255.255.252");
        p2pInterfaces43 = address.Assign (p2pDevices43);
        address.SetBase ("10.2.94.0", "255.255.255.252");
        p2pInterfaces44 = address.Assign (p2pDevices44);
        address.SetBase ("10.2.95.0", "255.255.255.252");
        p2pInterfaces45 = address.Assign (p2pDevices45);
        

        address.SetBase ("10.2.200.0", "255.255.255.0");
        Ipv4InterfaceContainer csmaInterfaces;
        csmaInterfaces = address.Assign (csmaDevices);

        //Assign IP addresses to cloud nodes
        Ipv4AddressHelper ipv4;
          ipv4.SetBase("10.1.1.0", "255.255.255.0");
          Ipv4InterfaceContainer i1 = ipv4.Assign(d1);
          ipv4.SetBase("10.1.2.0", "255.255.255.0");
          Ipv4InterfaceContainer i2 = ipv4.Assign(d2);
          ipv4.SetBase("10.1.3.0", "255.255.255.0");
          Ipv4InterfaceContainer i3 = ipv4.Assign(d3);
          ipv4.SetBase("10.1.4.0", "255.255.255.0");
          Ipv4InterfaceContainer i4 = ipv4.Assign(d4);
          ipv4.SetBase("10.1.5.0", "255.255.255.0");
          Ipv4InterfaceContainer i51 = ipv4.Assign(d51);
          ipv4.SetBase("10.1.6.0", "255.255.255.0");
          Ipv4InterfaceContainer i52 = ipv4.Assign(d52);      
          ipv4.SetBase("10.1.7.0", "255.255.255.0");
          Ipv4InterfaceContainer i61 = ipv4.Assign(d61);
          ipv4.SetBase("10.1.8.0", "255.255.255.0");
          Ipv4InterfaceContainer i62 = ipv4.Assign(d62);
          ipv4.SetBase("10.1.9.0", "255.255.255.0");
          Ipv4InterfaceContainer i71 = ipv4.Assign(d71);
          ipv4.SetBase("10.1.10.0", "255.255.255.0");
          Ipv4InterfaceContainer i72 = ipv4.Assign(d72);
          ipv4.SetBase("10.1.11.0", "255.255.255.0");
          Ipv4InterfaceContainer i81 = ipv4.Assign(d81);
          ipv4.SetBase("10.1.12.0", "255.255.255.0");
          Ipv4InterfaceContainer i82 = ipv4.Assign(d82);
          ipv4.SetBase("10.1.13.0", "255.255.255.0");
          Ipv4InterfaceContainer i91 = ipv4.Assign(d91);
          ipv4.SetBase("10.1.14.0", "255.255.255.0");
          Ipv4InterfaceContainer i92 = ipv4.Assign(d92);
          ipv4.SetBase("10.1.15.0", "255.255.255.0");
          Ipv4InterfaceContainer ix = ipv4.Assign(dx);
          ipv4.SetBase("10.1.16.0", "255.255.255.0");
          Ipv4InterfaceContainer iy = ipv4.Assign(dy);
          cout << " Address assigned " << endl;
    
      NS_LOG_INFO ("Create applications.");
      //
      // Create a packet sink on the star "hub" to receive packets.
      // 
      uint16_t port = 50000;
      Address hubLocalAddress (InetSocketAddress (Ipv4Address::GetAny (), port));
      PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", hubLocalAddress);
      ApplicationContainer hubApp1 = packetSinkHelper.Install (c1.Get(0));

      UdpEchoServerHelper echoServer (9);
      ApplicationContainer RandApp1 = echoServer.Install (c1.Get(0));
      ApplicationContainer RandApp2 = echoServer.Install (c2.Get(0));
      ApplicationContainer RandApp3 = echoServer.Install (c3.Get(0));
      ApplicationContainer RandApp4 = echoServer.Install (c4.Get(0));
      
      hubApp1.Start (Seconds (1.0));
      
      hubApp1.Stop (Seconds (100.0));
      
     // double myRandomNo;
    /*    for(uint32_t i=0;i<10;i++)
        {
        myRandomNo = x->GetValue ();
        cout<<"My random uniform random variable is: "<< myRandomNo <<endl;
        }*/
      //Ptr<UniformRandomVariable> x = CreateObject<UniformRandomVariable> ();
      //myRandomNo = x->GetValue ();
      RandApp1.Start (Seconds (1.0));   
      RandApp2.Start (Seconds (1.0));    
      RandApp3.Start (Seconds (1.0));    
      RandApp4.Start (Seconds (1.0));
      
      
      RandApp1.Stop (Seconds (100.0));
      RandApp2.Stop (Seconds (100.0));
      RandApp3.Stop (Seconds (100.0));
      RandApp4.Stop (Seconds (100.0));
      
    
    
      //
      // Create OnOff applications to send TCP to the hub, one on each spoke node.
      //
      OnOffHelper onOffHelper ("ns3::TcpSocketFactory", Address ());
      onOffHelper.SetAttribute ("OnTime", StringValue ("ns3::ExponentialRandomVariable"));
      onOffHelper.SetAttribute ("OffTime", StringValue ("ns3::ExponentialRandomVariable"));
    
      cout<<"IPv4 address testing..."<<endl;
      Ptr<Ipv4> IP1 = c1.Get(0)->GetObject<Ipv4> (); // Get Ipv4 instance of the node
      Ipv4Address addr1 = IP1->GetAddress (1, 0).GetLocal ();
      Ptr<Ipv4> IP2 = c2.Get(0)->GetObject<Ipv4> (); // Get Ipv4 instance of the node
      Ipv4Address addr2 = IP2->GetAddress (1, 0).GetLocal ();
      Ptr<Ipv4> IP3 = c3.Get(0)->GetObject<Ipv4> (); // Get Ipv4 instance of the node
      Ipv4Address addr3 = IP3->GetAddress (1, 0).GetLocal ();
      Ptr<Ipv4> IP4 = c4.Get(0)->GetObject<Ipv4> (); // Get Ipv4 instance of the node
      Ipv4Address addr4 = IP4->GetAddress (1, 0).GetLocal ();
      cout<<"IP address of client 1 interface 1 is: "<<addr1<<" "<< addr2<<" "<< addr3 << " "<< addr4<<endl;
      cout<<"IPv4 testing over"<<endl;

      Ptr<UniformRandomVariable> x = CreateObject<UniformRandomVariable> ();
      Ptr<ExponentialRandomVariable> y = CreateObject<ExponentialRandomVariable> ();
      UdpEchoClientHelper echoClient1 (addr1, 9);     
      UdpEchoClientHelper echoClient2 (addr2, 9); 
      UdpEchoClientHelper echoClient3 (addr3, 9); 
      UdpEchoClientHelper echoClient4 (addr4, 9); 
      myRandomNo = x->GetValue ();
      echoClient1.SetAttribute ("Interval", TimeValue (Seconds (myRandomNo+1.0)));   
      myRandomNo = x->GetValue ();
      echoClient2.SetAttribute ("Interval", TimeValue (Seconds (myRandomNo+1.0)));
      myRandomNo = x->GetValue ();
      echoClient3.SetAttribute ("Interval", TimeValue (Seconds (myRandomNo+1.0)));
      myRandomNo = x->GetValue ();
      echoClient4.SetAttribute ("Interval", TimeValue (Seconds (myRandomNo+1.0)));
      myRandomNo = y->GetValue (40,1024);
      randNo = int(myRandomNo);
      echoClient1.SetAttribute ("PacketSize", UintegerValue (randNo));
      myRandomNo = y->GetValue (40,1024);
      randNo = int(myRandomNo);
      echoClient2.SetAttribute ("PacketSize", UintegerValue (randNo));
      myRandomNo = y->GetValue (40,1024);
      randNo = int(myRandomNo);
      echoClient3.SetAttribute ("PacketSize", UintegerValue (randNo));
      myRandomNo = y->GetValue (40,1024);
      randNo = int(myRandomNo);
      echoClient4.SetAttribute ("PacketSize", UintegerValue (randNo));

      ApplicationContainer spokeApps;
      ApplicationContainer RandSpokeApps, RandSpokeApps1;
      myRandomNo = x->GetValue();
      for (uint32_t i = 0; i < star1.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr1, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star1.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          cout<< "The random number is: "<<randNo <<endl;
          if(randNo ==0)
          RandSpokeApps.Add (echoClient1.Install (star1.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps.Add (echoClient2.Install (star1.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps.Add (echoClient3.Install (star1.GetSpokeNode(i)));
          else
          RandSpokeApps.Add (echoClient4.Install (star1.GetSpokeNode(i)));
       }
      for (uint32_t i = 0; i < star2.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr1, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star2.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps.Add (echoClient1.Install (star2.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps.Add (echoClient2.Install (star2.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps.Add (echoClient3.Install (star2.GetSpokeNode(i)));
          else
          RandSpokeApps.Add (echoClient4.Install (star2.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star3.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr2, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star3.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps.Add (echoClient1.Install (star3.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps.Add (echoClient2.Install (star3.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps.Add (echoClient3.Install (star3.GetSpokeNode(i)));
          else
          RandSpokeApps.Add (echoClient4.Install (star3.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star4.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr2, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star4.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps.Add (echoClient1.Install (star4.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps.Add (echoClient2.Install (star4.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps.Add (echoClient3.Install (star4.GetSpokeNode(i)));
          else
          RandSpokeApps.Add (echoClient4.Install (star4.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star5.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr3, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star5.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps.Add (echoClient1.Install (star5.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps.Add (echoClient2.Install (star5.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps.Add (echoClient3.Install (star5.GetSpokeNode(i)));
          else
          RandSpokeApps.Add (echoClient4.Install (star5.GetSpokeNode(i)));
       }
        for (uint32_t i = 0; i < star6.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr3, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star6.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps.Add (echoClient1.Install (star6.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps.Add (echoClient2.Install (star6.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps.Add (echoClient3.Install (star6.GetSpokeNode(i)));
          else
          RandSpokeApps.Add (echoClient4.Install (star6.GetSpokeNode(i)));
       }
      for (uint32_t i = 0; i < star7.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr4, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star7.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps.Add (echoClient1.Install (star7.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps.Add (echoClient2.Install (star7.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps.Add (echoClient3.Install (star7.GetSpokeNode(i)));
          else
          RandSpokeApps.Add (echoClient4.Install (star7.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star8.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr4, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star8.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps.Add (echoClient1.Install (star8.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps.Add (echoClient2.Install (star8.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps.Add (echoClient3.Install (star8.GetSpokeNode(i)));
          else
          RandSpokeApps.Add (echoClient4.Install (star8.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star9.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr1, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star9.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps.Add (echoClient1.Install (star9.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps.Add (echoClient2.Install (star9.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps.Add (echoClient3.Install (star9.GetSpokeNode(i)));
          else
          RandSpokeApps.Add (echoClient4.Install (star9.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star10.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr1, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star10.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps.Add (echoClient1.Install (star10.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps.Add (echoClient2.Install (star10.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps.Add (echoClient3.Install (star10.GetSpokeNode(i)));
          else
          RandSpokeApps.Add (echoClient4.Install (star10.GetSpokeNode(i)));
       }
        for (uint32_t i = 0; i < star11.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr3, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star11.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps.Add (echoClient1.Install (star11.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps.Add (echoClient2.Install (star11.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps.Add (echoClient3.Install (star11.GetSpokeNode(i)));
          else
          RandSpokeApps.Add (echoClient4.Install (star11.GetSpokeNode(i)));
       }
      for (uint32_t i = 0; i < star12.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr4, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star12.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps.Add (echoClient1.Install (star12.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps.Add (echoClient2.Install (star12.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps.Add (echoClient3.Install (star12.GetSpokeNode(i)));
          else
          RandSpokeApps.Add (echoClient4.Install (star12.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star13.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr4, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star13.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps.Add (echoClient1.Install (star13.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps.Add (echoClient2.Install (star13.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps.Add (echoClient3.Install (star13.GetSpokeNode(i)));
          else
          RandSpokeApps.Add (echoClient4.Install (star13.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star14.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr1, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star14.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps1.Add (echoClient1.Install (star14.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps1.Add (echoClient2.Install (star14.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps1.Add (echoClient3.Install (star14.GetSpokeNode(i)));
          else
          RandSpokeApps1.Add (echoClient4.Install (star14.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star15.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr1, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star15.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps1.Add (echoClient1.Install (star15.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps1.Add (echoClient2.Install (star15.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps1.Add (echoClient3.Install (star15.GetSpokeNode(i)));
          else
          RandSpokeApps1.Add (echoClient4.Install (star15.GetSpokeNode(i)));
       }
        for (uint32_t i = 0; i < star16.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr3, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star16.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps1.Add (echoClient1.Install (star16.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps1.Add (echoClient2.Install (star16.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps1.Add (echoClient3.Install (star16.GetSpokeNode(i)));
          else
          RandSpokeApps1.Add (echoClient4.Install (star16.GetSpokeNode(i)));
       }
      for (uint32_t i = 0; i < star17.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr4, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star17.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps1.Add (echoClient1.Install (star17.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps1.Add (echoClient2.Install (star17.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps1.Add (echoClient3.Install (star17.GetSpokeNode(i)));
          else
          RandSpokeApps1.Add (echoClient4.Install (star17.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star18.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr4, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star18.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps1.Add (echoClient1.Install (star18.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps1.Add (echoClient2.Install (star18.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps1.Add (echoClient3.Install (star18.GetSpokeNode(i)));
          else
          RandSpokeApps1.Add (echoClient4.Install (star18.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star19.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr1, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star19.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps1.Add (echoClient1.Install (star19.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps1.Add (echoClient2.Install (star19.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps1.Add (echoClient3.Install (star19.GetSpokeNode(i)));
          else
          RandSpokeApps1.Add (echoClient4.Install (star19.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star20.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr1, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star20.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps1.Add (echoClient1.Install (star20.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps1.Add (echoClient2.Install (star20.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps1.Add (echoClient3.Install (star20.GetSpokeNode(i)));
          else
          RandSpokeApps1.Add (echoClient4.Install (star20.GetSpokeNode(i)));
       }
        for (uint32_t i = 0; i < star21.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr3, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star21.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps1.Add (echoClient1.Install (star21.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps1.Add (echoClient2.Install (star21.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps1.Add (echoClient3.Install (star21.GetSpokeNode(i)));
          else
          RandSpokeApps1.Add (echoClient4.Install (star21.GetSpokeNode(i)));
       }
      for (uint32_t i = 0; i < star22.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr4, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star22.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps1.Add (echoClient1.Install (star22.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps1.Add (echoClient2.Install (star22.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps1.Add (echoClient3.Install (star22.GetSpokeNode(i)));
          else
          RandSpokeApps1.Add (echoClient4.Install (star22.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star23.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr4, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star23.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps1.Add (echoClient1.Install (star23.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps1.Add (echoClient2.Install (star23.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps1.Add (echoClient3.Install (star23.GetSpokeNode(i)));
          else
          RandSpokeApps1.Add (echoClient4.Install (star23.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star24.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr1, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star24.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps1.Add (echoClient1.Install (star24.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps1.Add (echoClient2.Install (star24.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps1.Add (echoClient3.Install (star24.GetSpokeNode(i)));
          else
          RandSpokeApps1.Add (echoClient4.Install (star24.GetSpokeNode(i)));
       }
       for (uint32_t i = 0; i < star25.SpokeCount (); ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr1, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add (onOffHelper.Install (star15.GetSpokeNode(i)));
          randNo = int(4*(x->GetValue ()));
          if(randNo ==0)
          RandSpokeApps1.Add (echoClient1.Install (star25.GetSpokeNode(i)));
          else if(randNo ==1)
          RandSpokeApps1.Add (echoClient2.Install (star25.GetSpokeNode(i)));
          else if(randNo ==2)
          RandSpokeApps1.Add (echoClient3.Install (star25.GetSpokeNode(i)));
          else
          RandSpokeApps1.Add (echoClient4.Install (star25.GetSpokeNode(i)));
       }
      for (uint32_t i = 1; i <= nCsma; ++i)
        {
          AddressValue remoteAddress (InetSocketAddress (addr1, port));
          onOffHelper.SetAttribute ("Remote", remoteAddress);
          spokeApps.Add(onOffHelper.Install (csmaNodes.Get(i)));
       }
        //For DDoS attack
     spokeApps.Start (Seconds (30.0));
     spokeApps.Stop (Seconds (40.0));


        //For random traffic generation
     RandSpokeApps.Start(Seconds (15.0));
     RandSpokeApps.Stop(Seconds (100.0));

     RandSpokeApps1.Start(Seconds (20.0));
     RandSpokeApps1.Stop(Seconds (100.0));
      
     
     NS_LOG_INFO ("Enable static global routing.");
     //
     // Turn on global static routing so we can actually be routed across the star.
     //
     //You need to uncomment the below line and solve the error
     Ipv4GlobalRoutingHelper::PopulateRoutingTables ();
   
     NS_LOG_INFO ("Enable pcap tracing.");
     //
     // Do pcap tracing on all point-to-point devices on all nodes.
     //
     pointToPoint.EnablePcap ("First_pcap", p2pNodes12.Get(0)->GetId(),0);
     pointToPoint.EnablePcap ("Second_pcap", p2pNodes17.Get(0)->GetId(),0);
     pointToPoint.EnablePcap ("Third_pcap", p2pNodes17.Get(1)->GetId(),0);
     pointToPoint.EnablePcap ("Fourth_pcap", l10.Get(0)->GetId(),0);
     pointToPoint.EnablePcap ("Fifth_pcap",l9.Get(0)->GetId(),0);
     //pointToPoint.EnableAscii ("First_trace", p2pDevices15);
     pointToPoint.EnableAscii ("First_trace", p2pDevices16);
     pointToPoint.EnableAscii ("Second_trace", p2pDevices20);     
     //pointToPoint.EnableAscii ("Fifth_trace", p2pDevices21);
     //pointToPoint.EnableAscii ("Sixth_trace", p2pDevices22);
     pointToPoint.EnableAscii ("Third_trace", p2pDevices23);    

      

     // Setting up NetAnim
        AnimationInterface anim("Project_topology.xml");
        anim.SetConstantPosition(c1.Get(0),10.0,10.0);
            anim.SetConstantPosition(c2.Get(0),20.0,10.0);
            anim.SetConstantPosition(c3.Get(0),30.0,10.0);
            anim.SetConstantPosition(c4.Get(0),40.0,10.0);
            anim.SetConstantPosition(l1.Get(0),10.0,20.0);
            anim.SetConstantPosition(l2.Get(0),20.0,20.0);
            anim.SetConstantPosition(l3.Get(0),30.0,20.0);
            anim.SetConstantPosition(l4.Get(0),40.0,20.0);
            anim.SetConstantPosition(l5.Get(0),10.0,30.0);
            anim.SetConstantPosition(l6.Get(0),20.0,30.0);
            anim.SetConstantPosition(l7.Get(0),30.0,30.0);
            anim.SetConstantPosition(l8.Get(0),40.0,30.0);
            anim.SetConstantPosition(l9.Get(0),15.0,40.0);
            anim.SetConstantPosition(l10.Get(0),35.0,40.0);

        anim.SetConstantPosition(star1.GetHub(),10.0,75.0);
        anim.SetConstantPosition(star2.GetHub(),10.0,65.0);
        anim.SetConstantPosition(star3.GetHub(),40.0,65.0);
        anim.SetConstantPosition(star4.GetHub(),40.0,75.0);
        anim.SetConstantPosition(star5.GetHub(),10.0,85.0);

        anim.SetConstantPosition(star6.GetHub(),70.0,75.0);
        anim.SetConstantPosition(star7.GetHub(),70.0,65.0);
        anim.SetConstantPosition(star8.GetHub(),100.0,65.0);
        anim.SetConstantPosition(star9.GetHub(),100.0,75.0);
        anim.SetConstantPosition(star10.GetHub(),70.0,85.0);

        anim.SetConstantPosition(star11.GetHub(),130.0,75.0);
        anim.SetConstantPosition(star12.GetHub(),130.0,65.0);
        anim.SetConstantPosition(star13.GetHub(),160.0,65.0);
        anim.SetConstantPosition(star14.GetHub(),160.0,75.0);
        anim.SetConstantPosition(star15.GetHub(),130.0,85.0);

        anim.SetConstantPosition(star16.GetHub(),10.0,110.0);
        anim.SetConstantPosition(star17.GetHub(),10.0,100.0);
        anim.SetConstantPosition(star18.GetHub(),40.0,100.0);
        anim.SetConstantPosition(star19.GetHub(),40.0,110.0);
        anim.SetConstantPosition(star20.GetHub(),10.0,120.0);

        anim.SetConstantPosition(star21.GetHub(),70.0,110.0);
        anim.SetConstantPosition(star22.GetHub(),70.0,100.0);
        anim.SetConstantPosition(star23.GetHub(),100.0,100.0);
        anim.SetConstantPosition(star24.GetHub(),100.0,110.0);
        anim.SetConstantPosition(star25.GetHub(),70.0,120.0);
     for(uint32_t i=0; i<star1.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star1.GetSpokeNode(i),double(i*2),80.0);
        }      
     for(uint32_t i=0; i<star2.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star2.GetSpokeNode(i),double(i*2),70.0);
        }  
        for(uint32_t i=0; i<star3.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star3.GetSpokeNode(i),double(i*2+25),70.0);
        }      
     for(uint32_t i=0; i<star4.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star4.GetSpokeNode(i),double(i*2+25),80.0);
        }  
        for(uint32_t i=0; i<star5.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star5.GetSpokeNode(i),double(i*2),90.0);
        }  
     for(uint32_t i=0; i<star6.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star6.GetSpokeNode(i),double(i*2+60),80.0);
        }      
     for(uint32_t i=0; i<star7.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star7.GetSpokeNode(i),double(i*2+60),70.0);
        }  
        for(uint32_t i=0; i<star8.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star8.GetSpokeNode(i),double(i*2+90),70.0);
        }      
     for(uint32_t i=0; i<star9.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star9.GetSpokeNode(i),double(i*2+90),80.0);
        }  
        for(uint32_t i=0; i<star10.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star10.GetSpokeNode(i),double(i*2+60),90.0);
        } 
        for(uint32_t i=0; i<star11.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star11.GetSpokeNode(i),double(i*2+120),80.0);
        }      
     for(uint32_t i=0; i<star12.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star12.GetSpokeNode(i),double(i*2+120),70.0);
        }  
        for(uint32_t i=0; i<star13.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star13.GetSpokeNode(i),double(i*2+150),70.0);
        }      
     for(uint32_t i=0; i<star14.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star14.GetSpokeNode(i),double(i*2+150),80.0);
        }  
        for(uint32_t i=0; i<star15.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star15.GetSpokeNode(i),double(i*2+120),90.0);
        } 
        for(uint32_t i=0; i<star16.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star16.GetSpokeNode(i),double(i*2),115.0);
        }      
     for(uint32_t i=0; i<star17.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star17.GetSpokeNode(i),double(i*2),105.0);
        }  
        for(uint32_t i=0; i<star18.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star18.GetSpokeNode(i),double(i*2+25),105.0);
        }      
     for(uint32_t i=0; i<star19.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star19.GetSpokeNode(i),double(i*2+25),115.0);
        }  
        for(uint32_t i=0; i<star20.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star20.GetSpokeNode(i),double(i*2),125.0);
        } 
        for(uint32_t i=0; i<star21.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star21.GetSpokeNode(i),double(i*2+60),115.0);
        }      
     for(uint32_t i=0; i<star22.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star22.GetSpokeNode(i),double(i*2+60),105.0);
        }  
        for(uint32_t i=0; i<star23.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star23.GetSpokeNode(i),double(i*2+90),105.0);
        }      
     for(uint32_t i=0; i<star24.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star24.GetSpokeNode(i),double(i*2+90),115.0);
        }  
        for(uint32_t i=0; i<star25.SpokeCount(); i++)
        {
        anim.SetConstantPosition(star25.GetSpokeNode(i),double(i*2+60),125.0);
        } 
     for (uint32_t j=1;j<=nCsma;j++)
        {
        anim.SetConstantPosition(csmaNodes.Get(j),double(2*j+5),75.0);
         }
        anim.SetConstantPosition(p2pNodes.Get(0),20.0,63.0);
        anim.SetConstantPosition(p2pNodes.Get(1),20.0,73.0);
        anim.SetConstantPosition(p2pBB.Get(1),20.0,83.0);
        anim.SetConstantPosition(p2pNodes6.Get(0),75.0,63.0);
        anim.SetConstantPosition(p2pNodes6.Get(1),75.0,73.0);
        anim.SetConstantPosition(p2pNodes12.Get(0),52.0,50.0);
        anim.SetConstantPosition(p2pNodes17.Get(0),42.0,50.0);
        anim.SetConstantPosition(p2pNodes17.Get(1),62.0,50.0);

        anim.SetConstantPosition(p2pNodes24.Get(0),145.0,63.0);
        anim.SetConstantPosition(p2pNodes24.Get(1),145.0,73.0);
        anim.SetConstantPosition(p2pNodes24.Get(2),25.0,97.0);
        anim.SetConstantPosition(p2pNodes24.Get(3),25.0,107.0);
        anim.SetConstantPosition(p2pNodes24.Get(4),85.0,97.0);
        anim.SetConstantPosition(p2pNodes24.Get(5),85.0,107.0);
        
        //for (uint32_t i=0;i<100;i=i+10)
        //Simulator::Schedule(Seconds(i), &handler,i); 
     Simulator::Stop();
     NS_LOG_INFO ("Run Simulation.");
     Simulator::Run ();
     Simulator::Destroy ();
     NS_LOG_INFO ("Done.");
   
     return 0;
   }

