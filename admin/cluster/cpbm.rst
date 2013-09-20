.. index:: Citrix CPBM

Citrix CPBM
===========

The `Citrix Cloud Portal Business Mangaer (CPBM) <http://www.citrix.com/products/cloudportal-business-manager/overview.html>`__ is a portal for provisioning hosted apps, desktops, services and Infrastructure-as-a-Service (IaaS) from the cloud. With the Stackato Connector, it can provision a Stackato PaaS.

CPBM Stackato Connector Installation
------------------------------------

1. `Download a Stackato VM <http://activestate.com/stackato/download_vm>`__

2. Boot the Stackato VM anywhere on the network and configure as per the :ref:`Server Configuration <server>` documentation.

3. Add a DNS entry for the Stackato instance. This **must be subdomain of the CPBM instance** for SSO to work.


CPBM Stackato Connector Usage
-----------------------------

1. Log in to your Citrix Cloud Portal

2. On the **Home** tab select the **All Services** tab. **ActiveState Stackato** should be listed.

3. Click the **Enable** button on the **ActiveState Stackato** service.

4. Step through the wizard (accept terms, etc.)

5. Add tenant roles: Every role should be "Stackato User".

6. After the wizard completes, the page will reload showing an "Add" instead of "Enable" button.

7. Click the **Add** button

8. Follow the Add Service Instance wizard, for example:

  * **Service Instance Description**
  
    * Name: stackato-X
    * Code: SX
    * Description: Stackato PaaS X (optional)

  * **Service Details**
  
    * Stackato Location: api.stackato.cpbm-jw.com
    * Advanced:
    
      * Existing Stackato admin email: stackato@example.com
      * Existing Stackato admin password: yourpass

  * **Default Product Selections**
  
    * Check "Memory Limit"
    * Under "Category, select "Infrastructure: Platform Hosting" (optional)
    * Under "Required Product Units", select GB 
   
  * **Default Product Charges**
  
    * Memory Limit: 10.00
    * This setting is the default Product price. For example, a value of
      '10.00' would charge $10 for each GB over the limit. This is
      different from the product bundle, which is set up later.
    
  * **Review and Confirm**
  
    * Check that the settings are correct, then click **Add** 
    
