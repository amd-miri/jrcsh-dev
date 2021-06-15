<?php

/**
 * @file
 * Encryption logic for nexteuropa_dashboard_agent.
 */

/**
 * Class NextEuropaDashboardAgentEncryption.
 */
class NextEuropaDashboardAgentEncryption {

  /**
   * NE Dashboard Agent: create a new token.
   */
  public static function getToken() {
    $chars = array_merge(
      range(0, 9),
      range('a', 'z'),
      range('A', 'Z'),
      range(0, 99)
    );
    shuffle($chars);

    $token = "";
    for ($i = 0; $i < 8; $i++) {
      $token .= $chars[$i];
    }

    return $token;
  }

  /**
   * NE Dashboard Agent: encrypt a plaintext using openssl encryption method.
   *
   * @param string $plaintext
   *   The plain text to encrypt.
   *
   * @return string
   *   The given plain text encoded to utf8 and encrypted.
   *
   * @throws \Exception
   */
  public static function encrypt($plaintext) {
    $encryption_token = _nexteuropa_dashboard_agent_get_token('nexteuropa_dashboard_agent_encrypt_token');
    if ('Error-no-token' === $encryption_token) {
      $error = 'Error: No encryption token defined.';
      throw new Exception($error);
    }

    $key = hash("SHA256", $encryption_token, TRUE);
    $plaintext_utf8 = utf8_encode($plaintext);

    $iv_size = 16;
    $iv = openssl_random_pseudo_bytes($iv_size);
    $cyphertext = openssl_encrypt($plaintext_utf8, 'AES-128-CBC', $key, OPENSSL_RAW_DATA, $iv);

    return base64_encode($iv . $cyphertext);
  }

}
