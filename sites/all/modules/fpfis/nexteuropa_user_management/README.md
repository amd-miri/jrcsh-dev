NextEuropa User Management

# Setting up
You will need to add into the settings.php one of the following to 'variable':
```php
$conf['nexteuropa_user_management_banned_roles'] = array();
$conf['nexteuropa_user_management_banned_role_ids'] = array();
```

Inside the `nexteuropa_user_management_banned_roles` include the role names
(string type) which you want to exclude as a grantable role by User management
users.  
Inside the `nexteuropa_user_management_banned_role_ids` include the role ids
(integer type except the two exception see below) which you want to exclude as a
grantable role by User management users. 

To exclude Administrator role use `<!!ADMIN_RID!!>` token in the
`nexteuropa_user_management_banned_role_ids` array.  
To exclude User management role use `<!!USER_MANAGER_RID!!>` token in the 
`nexteuropa_user_management_banned_role_ids` array.

So to exclude as grantable role for User management user, put this into the
settings.php:
```php
$conf['nexteuropa_user_management_banned_role_ids'] = array(
  '<!!ADMIN_RID!!>',
  '<!!USER_MANAGER_RID!!>',
);
```

## Default values for setting variables
If `nexteuropa_user_management_banned_roles` remains undefined, it will be
considered as an empty array.  
If the `nexteuropa_user_management_banned_role_ids` remains undefined, it will
be considered as admin and user management was set.  
The two condition above are independent from eachother, by defining role names,
won't remove role ids' default values.
